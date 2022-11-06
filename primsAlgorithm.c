/**
 * @file primsAlgorithm.c
 * @author Ahmed Aly (aaly24@amherst.edu)
 * @brief 
 * @version 0.1
 * @date 2022-11-05
 * Runs Prim's algorithm on a graph to find the minimum spanning tree.
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>




/**
 * @brief A struct that represents a vertex in a graph.
 * 
 */
typedef struct Vertex{
    int id; // the id of the vertex
    Vertex** neighbors; // array of pointers of neighbors of the vertex
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
 * @brief reads a graph from a file through the connections between vertices
 * 
 * @param graph 
 * @param numVertices 
 * @param numEdges 
 * @return int 
 */
int readGraphComponents(Graph* graph, int numVertices, int numEdges){
    while (numVertices > numVertices){ // while there are still vertices to be read 
        // read the two vertices and the weight of the edge 
        int u, v, weight;
        int result = scanf("%c %c %d\n", &u, &v, &weight); // read the two vertices and the weight of the edge
        if (result == EOF){
            // if EOF is found, exit w error
            fprintf(stderr, "Error: EOF found before all vertices were read from file. Exiting..."); 
            exit(EXIT_FAILURE);
        } else if (result != 3){
            // if the number of items read is not 3, exit w error
            fprintf(stderr, "Error: Invalid input format. Exiting..."); 
            exit(EXIT_FAILURE);
        }
        
        // check if the vertices are already in the graph. If so, add the edge to the graph. If not, add the vertices and the edge to the graph
        Vertex* vertex1 = NULL;
        Vertex* vertex2 = NULL;
        for (int i = 0; i < graph->numVertices; i++){
            if (graph->vertices[i]->id == u){
                vertex1 = graph->vertices[i]; // the first vertex is already in the graph
            }
            if (graph->vertices[i]->id == v){
                vertex2 = graph->vertices[i]; // the second vertex is already in the graph
            }
        }
        if (vertex1 == NULL){
            vertex1 = (Vertex*)malloc(sizeof(Vertex));
            vertex1->id = u; // set the id of the vertex
            vertex1->neighbors = (Vertex**)malloc(sizeof(Vertex*) * numVertices); // the maximum number of neighbors is the number of vertices in the graph
            graph->vertices[graph->numVertices] = vertex1; // add the vertex to the graph
            graph->numVertices++; // increment the number of vertices in the graph
        }
        if (vertex2 == NULL){
            vertex2 = (Vertex*)malloc(sizeof(Vertex));
            vertex2->id = v; // set the id of the vertex
            vertex2->neighbors = (Vertex**)malloc(sizeof(Vertex*) * numVertices); // the maximum number of neighbors is the number of vertices in the graph
            graph->vertices[graph->numVertices] = vertex2; // add the vertex to the graph
            graph->numVertices++; // increment the number of vertices in the graph
        }
        // check that the edge isn't already in the graph
        for (int i = 0; i < graph->numEdges; i++){
            if (graph->edges[i]->u == vertex1 && graph->edges[i]->v == vertex2){
                // print error message
                fprintf(stderr, "Error: Edge (%c, %c) already exists in the graph. Exiting...", vertex1->id, vertex2->id);
                printf("Redundant Edge from %c to %c", vertex1, vertex2);
                exit(EXIT_FAILURE);
            }
        }
        // add the edge to the graph
        Edge* edge = (Edge*)malloc(sizeof(Edge));
        edge->u = vertex1;
        edge->v = vertex2;
        edge->weight = weight;
        graph->edges[graph->numEdges] = edge; // add the edge to the graph
        graph->numEdges++; // increment the number of edges in the graph

        // add the edge to the neighbors of the vertices
        vertex1->neighbors[vertex1->numNeighbors] = vertex2;
        vertex1->numNeighbors++;
        vertex2->neighbors[vertex2->numNeighbors] = vertex1;
        vertex2->numNeighbors++;


    }
}


Graph* readGraph(char* filename){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file %s", filename);
        exit(1);
    } 
    int numVertices, numEdges;
    fscanf(fp, "%d %d\n", &numVertices, &numEdges);// read the number of vertices and edges
    // read graph edge by edge (the graph is connected and undirected)
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    readGraphComponents(graph, numVertices, numEdges);

