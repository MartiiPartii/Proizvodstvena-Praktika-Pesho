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

        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
        int curr = popQueue(dfsQueue);
        // printf("\nPopping %d", curr);
        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
        // printf("\n");

        for(int i = 0; i < map->vertexCount; i++) {
            int currNeighbourWeight = map->adjMatrix[curr][i];
            if(currNeighbourWeight && currNeighbourWeight <= 5) {
                if(!(police[i] && pesho[i])) {
                    pesho[i] = 1;
                    from[i] = curr;
                    if(currNeighbourWeight <= 3) {
                        police[i] = 1;
                        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
                        // printf("\nPushing %d", i);
                        pushQueue(dfsQueue, i);
                        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
                        // printf("\n");
                    }
                }
            }
        }
    }

    releaseQueue(dfsQueue);

    // printf("\n%6s ", "Pesho");
    // for(int i = 0; i < map->vertexCount; i++) {
    //     printf("%2d ", pesho[i]);
    // }
    // printf("\n%6s ", "Police");
    // for(int i = 0; i < map->vertexCount; i++) {
    //     printf("%2d ", police[i]);
    // }
    // printf("\n%6s ", "From");
    // for(int i = 0; i < map->vertexCount; i++) {
    //     printf("%2d ", from[i]);
    // }
}



int main() {
    // Graph * map = initGraph(6);

    // addEdge(map, 0, 4, 3);
    // addEdge(map, 0, 5, 3);
    // addEdge(map, 0, 1, 1);

    // addEdge(map, 1, 4, 4);
    // addEdge(map, 1, 3, 4);
    // addEdge(map, 1, 5, 4);

    // addEdge(map, 2, 4, 3);

    // addEdge(map, 4, 5, 2);

    // printGraph(map);

    Graph * map = initGraph(5);

    addEdge(map, 0, 1, 4);

    addEdge(map, 1, 2, 5);
    addEdge(map, 1, 3, 2);

    addEdge(map, 2, 4, 3);

    addEdge(map, 3, 4, 3);

    findPath(map, 2);
    
    return 0;
}