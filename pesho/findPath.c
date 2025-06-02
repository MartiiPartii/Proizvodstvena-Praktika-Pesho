#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"

int main() {
    Graph * map = initGraph(6);
    printGraph(map);
    
    return 0;
}