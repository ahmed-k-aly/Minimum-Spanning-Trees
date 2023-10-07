# Minimum Spanning Trees

This project is a C implementation of Minimum Spanning Trees (MST) using both Prim and Kruskal's algorithms. MST is a fundamental problem in graph theory, and this project provides efficient solutions for finding the minimum spanning tree in a given connected, undirected graph.

## Motivation
I wrote this to gain more insight into the intricacies of both algorithms for my COSC-311 Algorithms course at Amherst College. By manually implementing the algorithms and the required infrastructre to run them, I was able to fundamentally grasp the algorithms more as well as the MST problem.

## Introduction

A Minimum Spanning Tree (MST) of a graph is a subgraph that includes all the vertices of the original graph and connects them with the minimum possible total edge weight. This project demonstrates two popular algorithms for finding MSTs.

### Implementation
This projects reads in a graph as a set of weighted connections, such as (A B 10), signifying a direct edge from vertex A to B. It then runs both algorithms on the given graph.

### Prim's Algorithm

Prim's Algorithm starts with an arbitrary node and grows the MST one vertex at a time. It always selects the edge with the lowest weight that connects a vertex in the MST to a vertex outside it.

### Kruskal's Algorithm

Kruskal's Algorithm sorts all the edges in increasing order of their weights and adds them to the MST one by one, making sure that adding an edge won't form a cycle.

## Algorithm Differences

- **Prim's Algorithm:**
  - Starts with a single vertex and grows the MST.
  - Well-suited for dense graphs.
  - Typically implemented with a priority queue or a min-heap for efficiency.
  - Time complexity: O(V^2) with an adjacency matrix, O(E + V log V) with an adjacency list.

- **Kruskal's Algorithm:**
  - Sorts edges by weight and adds them to the MST one by one.
  - Well-suited for sparse graphs.
  - Typically implemented with a disjoint-set data structure (Union-Find) for cycle detection.
  - Time complexity: O(E log E) for sorting the edges, O(E log V) for the algorithm.

## Pros and Cons

### Prim's Algorithm:

- **Pros:**
  - Efficient for dense graphs.
  - Works well with a priority queue or min-heap.
  - Guarantees a connected MST.

- **Cons:**
  - Slower for sparse graphs.
  - Priority queue or min-heap implementation required for efficiency.

### Kruskal's Algorithm:

- **Pros:**
  - Efficient for sparse graphs.
  - Simplicity in implementation.
  - Works with any graph representation.

- **Cons:**
  - May produce a forest if the input graph is not connected.
  - Sorting edges can be expensive for very large graphs.

This project provides implementations of both algorithms, allowing you to choose the one that best suits your specific graph and performance requirements.
