#include "readGraph.h"



/**
 * @brief A struct to represent a tree node
 * 
 */
typedef struct TreeNode {
    Vertex* self; // the vertex of the node
    struct TreeNode* child; // the child of the node
    Edge* edge;
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
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->self = curr;
    root->child = NULL;
    root->edge = NULL;
    mst->root = root;
    mst->cost = 0;
    mst->size = 1;
    curr->visited = true;
    int i = graph->numVertices;
    while(i > 0){
        // find the cheapest connection from that edge that won't make a cycle 
        Edge* min = getMinEdge(root->self);
        if (min == NULL){
            printf("No more edges to add to MST");
            break;
        }

        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->self = (min->v == root->self ? min->u:min->v);
        // add that edge to the MST
        node->self = curr;
        root->child = node;
        root->edge = min;

        assert(!node->self->visited);
        node->self->visited = true; // mark the node visited 
        // repeat until all vertices are in the MST
        i--;
        mst->root = node;
        mst->size++;
        mst->cost += min->weight;
        root = node;
    }
    assert(mst->size == graph->numVertices);

    return *mst;
} 

void printMST(MST mst){
    TreeNode* curr = mst.root;
    while(curr != NULL){
        printf("Vertex: %c)", curr->self->id);
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
