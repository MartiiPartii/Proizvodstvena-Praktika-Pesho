#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"



void findPath(Graph * map, int startingPoint) {
    int * pesho = (int *) calloc(map->vertexCount, sizeof(int));
    ALLOC_ERR(pesho);

    int * police = (int *) calloc(map->vertexCount, sizeof(int));
    ALLOC_ERR(police);

    int * from = (int *) calloc(map->vertexCount, sizeof(int));
    ALLOC_ERR(from);
    for(int i = 0; i < map->vertexCount; i++) {
        from[i] = -1;
    }

    pesho[startingPoint] = 1;
    police[startingPoint] = 1;


    Queue * dfsQueue = initQueue(map->vertexCount);

    pushQueue(dfsQueue, startingPoint);
    while(dfsQueue->size) {
        int curr = popQueue(dfsQueue);
        for(int i = 0; i < map->vertexCount; i++) {
            int currNeighbourWeight = map->adjMatrix[curr][i];
            if(currNeighbourWeight && currNeighbourWeight <= 5) {
                // printf("\n%d -> %d: %d", curr, i, currNeighbourWeight);

                if(!(police[i] && pesho[i])) {
                    if(currNeighbourWeight <= 3) {
                        pesho[i] = 1;
                        police[i] = 1;
                        from[i] = curr;
                        pushQueue(dfsQueue, i);
                    }
                        // if(!pesho[i] && !police[i]) {
                        //     pushQueue(dfsQueue, i);
                        // }
                        // if(!police[i]) {
                            // pesho[i] = 1;
                            // police[i] = 1;
                            // from[i] = curr;
                        // }
                    // }
                }

                // if(currNeighbourWeight <= 3) {
                //     if(!pesho[i] && !police[i]) {
                //         pushQueue(dfsQueue, i);
                //     }
                //     if(!police[i]) {
                //         pesho[i] = 1;
                //         police[i] = 1;
                //         from[i] = curr;
                //     }
                // }
                // else if(!police[i]) {
                //     pesho[i] = 1;
                //     from[i] = curr;
                // }
            }
        }
    }

    releaseQueue(dfsQueue);
}



int main() {
    Graph * map = initGraph(6);

    addEdge(map, 0, 4, 3);
    addEdge(map, 0, 5, 3);
    addEdge(map, 0, 1, 1);

    addEdge(map, 1, 4, 4);
    addEdge(map, 1, 3, 4);
    addEdge(map, 1, 5, 4);

    addEdge(map, 2, 4, 3);

    addEdge(map, 4, 5, 2);

    // printGraph(map);
    findPath(map, 1);
    
    return 0;
}