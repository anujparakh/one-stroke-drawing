# one-stroke-drawing
A C++ program based on the Graph data structure to determine whether a given shape with given vertices and edges can be drawn in one stroke or not. This program implements the Graph structure using an Adjacency Matrix. More information on this can be found [here](https://www.geeksforgeeks.org/graph-and-its-representations/).

### Building and Running the Program
To build the project, download the repository locally and simply run the command `make all` to build. This creates the command line executable called findOneStroke. The program uses command line arguments to get the path of the file for the graph. Each argument supplied to the executable is processed for output. For example:

`./findOneStroke graph1.data` runs the program on just graph1.data.
`./findOneStroke graph1.data graph2.data` runs the program on graph1.data and graph2.data.
`./findOneStroke -all` is a special argument where the program is run on graph1.data through graph6.data.

The Graph.hpp and Graph.cpp files hold the logic to the Graph class which is behind everything. The main.cpp holds the testing case for parsing command line arguments and calling into the Graph class.

### Format of Input
The format of the input file is as follows: the first line contains the number of vertices and the number of edges, respectiely. The next lines contain the endpoints of edges. For example:

`5 6`<br>
`1 2`<br>
`1 2`<br>
`3 1`<br>
`2 4`<br>
`4 5`<br>
`5 2`<br>

represents the following picture:

![Alt text](Pictures/Graph5.png?raw=true "Title")

In this drawing, a path is possible and it would be listed in the output.

### Examples
There are 6 graphs provided in the examples graph1.data - graph6.data :
![Alt text](Pictures/Graph1.png?raw=true "Title")
Graph1.data
![Alt text](Pictures/Graph2.png?raw=true "Title")
Graph2.data
![Alt text](Pictures/Graph3.png?raw=true "Title")
Graph3.data
![Alt text](Pictures/Graph4.png?raw=true "Title")
Graph4.data
![Alt text](Pictures/Graph5.png?raw=true "Title")
Graph5.data
![Alt text](Pictures/Graph6.png?raw=true "Title")
Graph6.data