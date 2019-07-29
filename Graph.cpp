//
//  Graph.cpp
//  Programming Assignment 6
//
//  Created by Anuj Parakh on 4/17/19.
//  Copyright © 2019 Anuj Parakh. All rights reserved.
//

#include "Graph.hpp"
#include <algorithm>

using namespace std;


// Adding Edge to Graph
void Graph::addEdge(Edge edge)
{
    adjacencyMatrix [edge.vertice] [edge.endpoint] = CONNECTED;
    adjacencyMatrix [edge.endpoint] [edge.vertice] = CONNECTED;
    allEdges.push_back(edge);
}

// Deleting edge from graph
void Graph::deleteEdge(Edge edge)
{
    // set edges to 0
    adjacencyMatrix [edge.vertice] [edge.endpoint] = DISCONNECTED;
    adjacencyMatrix [edge.endpoint] [edge.vertice] = DISCONNECTED;
    
    // Look for edge to delete
    for (auto it = allEdges.begin(); it < allEdges.end(); ++it)
    {
        if (*it == edge)
        {
            allEdges.erase(it);
            break;
        }
    }
}

// Check if path is possible
bool Graph::isPathPossible()
{
    int numOdd = 0;
    
    // Go through each vertice
    for (auto verticeList: adjacencyMatrix)
    {
        int connections = 0;
        // Add up all connected edges
        for (auto connection: verticeList)
            if (connection == CONNECTED)
                ++connections;
        // If number of edges are odd
        if (connections % 2 == 1)
            ++numOdd;
    }
    
    // Path is possible ONLY if 0 or 2 vertices have odd number of edges
    return (numOdd == 0 || numOdd == 2);

}

// Check if the path is complete (assuming already checked if path is one stroke)
bool Graph::isPathComplete(vector <int> pathVertices)
{
    return (pathVertices.size() - 1) == allEdges.size();
}

// Function to Search for a path
vector<int> Graph::searchForPath()
{
    // Create a temporary copy of current graph
    Graph temp = *this;
    // Create a vector of vertices
    vector <int> pathVertices;
    
    // flag to see if path is found
    bool flag = false;
    // go through all the head vertices
    for (int i = 0; i < adjacencyMatrix.size(); ++i)
    {
        // if path is found
        if (searchForPath(i, pathVertices, temp))
        {
            // set the flag and get out of loop
            flag = true;
            break;
        }
        // clear the possible path
        pathVertices.clear();
    }

    // if path not found, return an empty vector
    if (!flag)
        return vector<int>();
    // otherwise return the path
    return pathVertices;
}

// HELPER function to return the ith element of a list
int get(list<int> _list, int _i)
{
    auto it = _list.begin();
    for(int i=0; i<_i; i++)
    {
        ++it;
    }
    return *it;
}

// Search for path Recursively
// Passing a vector of pathVertices and a temporarily changeable graph
bool Graph::searchForPath(int startVertice, vector <int> &pathVertices, Graph temp)
{
    // Push back the next vertice
    pathVertices.push_back(startVertice);
    
    bool isDisconnected = true;
    // If no more adjacent vertices
    for (auto toCheck: temp.adjacencyMatrix [startVertice])
        if (toCheck == CONNECTED)
        {
            isDisconnected = false;
            break;
        }
            
    if (isDisconnected)
    {
        // then return true if path is complete (true means path has been found)
        // false if path is not complete (need to go back)
        return isPathComplete (pathVertices);
    }

    // go through all the adjacent vertices
    for (int i = 0; i < temp.adjacencyMatrix[startVertice].size(); ++i)
    {
        int endpoint = i;
        if (temp.adjacencyMatrix[startVertice][endpoint] == 0)
            continue;
        
        // Get the edge to delete
        Edge edge (startVertice, endpoint);
        // delete the edge from the startVertice to the endPoint so that we can't use it again
        temp.deleteEdge(edge);

        // search for a path from the next point
        if (searchForPath(endpoint, pathVertices, temp))
            // path was found
            return true;
        else
        {
            // if path wasn't found, re-add the deleted edge
            temp.addEdge(edge);
            // delete the last vertice added to the path
            auto lastIt = pathVertices.end();
            --lastIt;
            pathVertices.erase(lastIt);
        }
    }
    
    // Path was not found
    return false;
}

// Output Operator Overloading
ostream& operator<<(ostream &out, Graph& graph)
{
    // For printing each vertice number
    int verticeNo = 1;
    for (auto verticeList: graph.adjacencyMatrix)
    {
        // Print the current vertice
        cout << verticeNo;
        // Go through all edges of vertice
        for (int i = 0; i < verticeList.size(); ++i)
        {
            if (verticeList [i])
                cout << " -> " << i + 1;
        }
        
        ++verticeNo;
        cout << endl;
    }
    return out;
}

// Input Operator Overloading
istream& operator>>(istream &in, Graph& graph)
{
    // Read in the number of vertices and edges
    int nVertices, nEdges;
    in >> nVertices >> nEdges;
    // Create new graph from info
    graph = Graph (nVertices);
    for (int i = 0; i < nEdges; ++i)
    {
        // Read in each edge from vertice to endpoint
        int vertice, endpoint;
        in >> vertice >> endpoint;

        // Decrement to make it start from 0
        // Add the new edge to the graph
        graph.addEdge(Edge (vertice - 1, endpoint - 1));
    }
    
    return in;
}
