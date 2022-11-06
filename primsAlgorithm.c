#include "readGraph.h"



/**
 * @brief A struct to represent a tree node
 * 
 */
typedef struct TreeNode {
    Vertex* parent;
    Vertex* child;
    Edge* edge;
    int weight;
} TreeNode;

/**
 * @brief A struct that defines a Minimum Spanning Tree 
 * 
 */
typedef struct MST {
    TreeNode *root;
    int cost;
    int size;
} MST;

Edge* getMinEdge(Vertex* v){
    // loop over all vertices and return the minimum valued edge
    Edge* minWeightEdge = (malloc(sizeof(Edge)));
    minWeightEdge->u = v;
    minWeightEdge->v = v;
    minWeightEdge->weight = INT_MAX;
    for (int i = 0; i < v->numNeighbors; i++){
        Edge *e = v->edges[i];
        if(e->u->visited && e->v->visited){
            //node will create a cycle, so skip
            continue;
        }
        if (e->weight < minWeightEdge->weight){
            minWeightEdge = e;
        }
    }
    if (minWeightEdge->u == minWeightEdge->v){
        return NULL;
    }
    assert(minWeightEdge->u != minWeightEdge->v);
    return minWeightEdge;
}


MST primsAlgorithm(Graph* graph){
    // declare a new MST
    MST* mst = (MST*)malloc(sizeof(MST));
    // choose a random vertex to start with
    Vertex* curr = graph->vertices[ rand() %graph->numVertices];
    curr->visited = true;
    int i = graph->numVertices;
    while(i > 0){
        // find the cheapest connection from that edge that won't make a cycle 
        Edge* min = getMinEdge(curr);
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        // add that edge to the MST
        node->parent = curr;
        node->child = (min->v == curr ? min->u:min->v);
        assert(!node->child->visited);
        node->child->visited = true; // mark the node visited 
        // repeat until all vertices are in the MST
        i--;
        curr = node->child;
        mst->root = node;
        mst->size++;
        mst->cost += min->weight;
    }
    assert(mst->size == graph->numVertices);

    return *mst;
} 


void printMST(MST mst){
    // print the MST
    printf("MST: \n");
    TreeNode* curr = mst.root;
    while(curr != NULL){
        printf("%d -> %d\n", curr->parent->id, curr->child->id);
        curr = curr->child;
    }
}


/**
 * @brief main 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv){
    Graph* graph = readGraph();
    MST mst = primsAlgorithm(graph);
    printMST(mst);
    return 0;
}
