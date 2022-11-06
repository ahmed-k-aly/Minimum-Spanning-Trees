#include "readGraph.h"

int main(int argc, char** argv){
    Graph* graph = readGraph();
    printGraph(graph);
    return 0;
}
