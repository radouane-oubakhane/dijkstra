# Dijkstra Algorithm in C

This is an implementation of Dijkstra's shortest path algorithm in C. It takes an adjacency matrix as input and returns the shortest distance from the source vertex to all other vertices in the graph.

## Getting Started

To get started with this code, simply clone the repository and compile the source file:

`git clone https://github.com/radouane-oubakhane/dijkstra.git`

`cd dijkstra`

`gcc main.c -o main`

Then, run the program:

`./main`

The input file should contain an adjacency matrix in the following format:

## Output

The program will output the shortest distance from the source vertex to all other vertices in the graph, as well as the path to each vertex. The output will be in the following format:

`------------------------------ - Les Chemins - ------------------------------`

`Le plus court chemin à partir du sommet 0 au sommet 1 est : 0 - 1`

`Le plus court chemin à partir du sommet 0 au sommet 2 est : 0 - 5 - 2`

`Le plus court chemin à partir du sommet 0 au sommet 3 est : 0 - 5 - 3`

`Le plus court chemin à partir du sommet 0 au sommet 4 est : 0 - 5 - 3 - 4`

`Le plus court chemin à partir du sommet 0 au sommet 5 est : 0 - 5`
