This C++ code defines a class named graph to represent an undirected graph with weighted edges. The graph class includes methods for adding edges, printing the graph, and performing breadth-first search (BFS) to find the shortest path between two specified vertices. Additionally, there is a method to read graph data from a file.

Here's a brief description of the code:

Class Definition:

The graph class contains an unordered map (adj) where each vertex is associated with a list of pairs representing its neighbors and the corresponding edge weights.
addedge Method:

This method adds an edge between two vertices with an optional weight. If the graph is undirected (determined by the direction parameter), it adds the reverse edge as well.
printGraph Method:

This method prints the graph, displaying each vertex and its connected vertices with their respective edge weights.
BFS Method:

This method performs a breadth-first search to find the shortest path between two specified vertices (start and end). It uses a queue to explore vertices level by level, updating distance and parent information as it goes.
readGraphFromFile Method:

This method reads graph data from a file, expecting each line to contain two vertices and an edge weight. It adds edges to the graph accordingly.
Main Function:

In the main function:
An instance of the graph class (g) is created.
The program attempts to open a file named "cities.txt" to read graph data.
The user is prompted to enter a starting city and a destination city.
The BFS algorithm is then applied to find and print the shortest path between the specified cities
