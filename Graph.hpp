//
//  Graph.hpp
//  Programming Assignment 6
//
//  Created by Anuj Parakh on 4/17/19.
//  Copyright © 2019 Anuj Parakh. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#define CONNECTED 1
#define DISCONNECTED 0


struct Edge
{
    int vertice, endpoint;
    Edge (int n_vertice = 0, int n_endpoint = 0): vertice(n_vertice), endpoint (n_endpoint)
    {}
    
    // Equality operator
    bool operator==(Edge &rhs)
    {
        // Check both ways
        return (vertice == rhs.vertice && endpoint == rhs.endpoint) || (vertice == rhs.endpoint && endpoint == rhs.vertice);
    }
    
};


class Graph
{
private:
    std::vector <std::vector<bool> > adjacencyMatrix;
    std::vector <Edge> allEdges;

    bool searchForPath (int, std::vector<int> &, Graph);
    bool isPathComplete (std::vector <int>);
public:
    Graph (int nVertices = 0): adjacencyMatrix(nVertices, std::vector<bool> (nVertices, DISCONNECTED)){}
    
    void addEdge (Edge);
    void deleteEdge (Edge);
    std::vector<int> searchForPath ();
    bool isPathPossible ();
    
    void printPath ();
    friend std::ostream& operator<<(std::ostream &, Graph&);
};
    
std::ostream& operator<<(std::ostream &, Graph&);
std::istream& operator>>(std::istream &, Graph&);



#endif /* Graph_hpp */
