/**
 * @file readGraph.h
 * @author Ahmed Aly (aaly24@amherst.edu)
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * Reads a graph from a file.
 * @copyright Copyright (c) 2022
 * 
 */

// avoid multiple inclusions
#if !defined(_READ_GRAPH_H_)
#define _READ_GRAPH_H_


// include the standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


// STRUCTS

/**
 * @brief A struct that represents a vertex in a graph.
 * 
 */
typedef struct Vertex{
    int id; // the id of the vertex
    struct Vertex** neighbors; // array of pointers of neighbors of the vertex
    int numNeighbors; // number of neighbors of the vertex

} Vertex;

/**
 * @brief A struct that represents an edge in the graph
 * 
 */
typedef struct Edge{
    Vertex* u; // the first vertex of the edge
    Vertex* v; // the second vertex of the edge
    int weight; // the weight of the edge
} Edge;

/**
 * @brief A struct that represents a graph
 * 
 */
typedef struct Graph{
    Vertex** vertices; // array of pointers to vertices in the graph
    Edge** edges; // array of pointers to edges in the graph
    int numVertices; // the number of vertices in the graph
    int numEdges; // the number of edges in the graph
} Graph;


/**
 * @brief A struct that represents a min heap node
 * 
 */
typedef struct MinHeapNode{
    Vertex* vertex; // the vertex of the node
    int key; // the key of the vertex
} MinHeapNode;

/**
 * @brief A struct that represents a min heap
 * 
 */
typedef struct MinHeap{
    MinHeapNode** nodes; // array of pointers to nodes in the heap
    int size; // the size of the heap
    int capacity; // the capacity of the heap
} MinHeap;

/**
 * @brief reads a graph from stdin and returns a pointer to the graph
 * 
 * @return Graph* a pointer to the graph
 */
Graph* readGraph();

/**
 * @brief Prints the graph
 * 
 * @param graph 
 */
void printGraph(Graph* graph);


#endif