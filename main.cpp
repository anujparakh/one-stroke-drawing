//
//  main.cpp
//  Programming Assignment 6
//
//  Created by Anuj Parakh on 4/17/19.
//  Copyright © 2019 Anuj Parakh. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdexcept>
#include "Graph.hpp"

using namespace std;


// Function to print a given path of vertices
void printPath(vector<int> pathVertices)
{
    // Print the first edge
    cout << "(" << pathVertices.front() + 1 << "," << pathVertices [1] + 1 << ")";
    // Go through the other vertices
    for (int i = 1; i < pathVertices.size() - 1; ++i)
    {
        // Print each vertice
        cout << " -> (" << pathVertices [i] + 1 << "," << pathVertices [i + 1] + 1 << ")";
    }
    
    cout << endl;
}

// Function to create a graph for a file and print the path findings
void searchPathsForGraphFromFile (string filename)
{
    // Read in the file
    ifstream infile (filename);
    
    if (infile.fail())
        // throw exception if file could not be opened
        throw runtime_error("Could not open file!");
    
    // Print the filename as a header
    cout << "****** File : " << filename << " ******" << endl << endl;

    // Create graph from file
    Graph graph;
    infile >> graph;
    infile.close();
    
    // Print the graph
    cout << "The graph read is : " << endl << graph << endl;
    
    // Check if path is possible
    if (!graph.isPathPossible())
    {
        cout << "Path CAN'T be found!!" << endl;
        // get out
        cout << "\n------------------------------------------------\n\n";
        return;
    }
    
    // Look for the path and print it
    cout << "PATH FOUND IS : " << endl;
    vector<int> pathFound = graph.searchForPath();
    printPath(pathFound);
    
    cout << "\n------------------------------------------------\n\n";
}

int main(int argc, const char * argv[])
{
    // Get the filename from either the arguments or the user
    ifstream infile;

    // If argument is provided
    if (argc > 1)
    {
        // Argument to do all files
        if (strcmp (argv[1], "-all") == 0)
        {
            cout << "\n------------------------------------------------\n\n";
            // Go through files and search for path for all of them
            for (int i = 1; i <= 6; ++i)
            {
                // Create filename using stringstream
                stringstream filename ("");
                filename << "graph" << i << ".data";
                searchPathsForGraphFromFile(filename.str());
            }
            
            // End function
            return 0;
        }
        
        // Go through each argument and do those files
        cout << "\n------------------------------------------------\n\n";
        for (int i = 1; i < argc; ++i)
        {
            searchPathsForGraphFromFile(argv [i]);
        }
    }
    // If no arguments provided, user must enter filename
    else
    {
        cout << "Enter filename : ";
        string filename;
        cin >> filename;
        cout << "\n------------------------------------------------\n\n";
        searchPathsForGraphFromFile(filename);
    }
    return 0;
}
