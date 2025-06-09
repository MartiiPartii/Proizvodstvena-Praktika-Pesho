#include <stdio.h>
#include <stdlib.h>
#include "../../dataStructures/vector/vector.h"
#include "../../dataStructures/graph/graph.h"
#include "../../errorHandle.h"


// Allocates memory for the arrays storing the visited nodes and the paths to them
static void initArrays(int vertexCount, int ** pesho, int ** police, int ** from) {
    *pesho = (int *) calloc(vertexCount, sizeof(int));
    ALLOC_ERR(*pesho);
    
    *police = (int *) calloc(vertexCount, sizeof(int));
    ALLOC_ERR(*police);
    
    *from = (int *) calloc(vertexCount, sizeof(int));
    ALLOC_ERR(*from);
    for(int i = 0; i < vertexCount; i++) {
        (*from)[i] = -1;
    }
}


// Finds the safe nodes from the graph
static void findSafeNodes(Graph * map, int startingPoint, int * pesho, int * police, int * from, int policeDistance, int peshoDistance) {
    Vector * dfsQueue = initVector(1);
        
    pushBackVector(dfsQueue, startingPoint);
    pesho[startingPoint] = 1;
    police[startingPoint] = 1;
    while(dfsQueue->size) {

        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
        int curr = popFrontVector(dfsQueue);
        // printf("\nPopping %d", curr);
        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
        // printf("\n");
        
        for(int i = 0; i < map->vertexCount; i++) {
            int currNeighbourWeight = map->adjMatrix[curr][i];
            if(currNeighbourWeight && currNeighbourWeight <= peshoDistance) {
                if(!(police[i] && pesho[i])) {
                    pesho[i] = 1;
                    from[i] = curr;
                    if(currNeighbourWeight <= policeDistance) {
                        police[i] = 1;
                        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
                        // printf("\nPushing %d", i);
                        pushBackVector(dfsQueue, i);
                        // printf("\nCapacity: %d; Size: %d", dfsQueue->capacity, dfsQueue->size);
                        // printf("\n");
                    }
                }
            }
        }
    }

    releaseVector(dfsQueue);
}


// Prints out the path from the starting point to the first safe node encountered
static int printPath(int vertexCount, int * pesho, int * police, int * from) {
    Vector * pathStack = initVector(1);

    for(int i = 0; i < vertexCount; i++) {
        if(pesho[i] && !police[i]) {
            pushBackVector(pathStack, i);
            int curr = from[i];
            while(curr >= 0) {
                pushBackVector(pathStack, curr);
                curr = from[curr];
            }
            break;
        }
    }

    if(pathStack->size) {
        printf("\n");
        while(pathStack->size) {
            int curr = popBackVector(pathStack);
            printf("%d ", curr);
            if(pathStack->size) printf("-> ");
        }
        printf("\n");
    } else {
        releaseVector(pathStack);
        return 0;
    }
    
    releaseVector(pathStack);
    return 1;
}


// Finds path for running away
void findPath(Graph * map, int startingPoint, int policeDistance, int peshoDistance) {
    // Checks if the starting point exists
    if(startingPoint >= map->vertexCount) {
        printf("\nPlease provide a valid starting point.");
        return;
    }

    if(peshoDistance > policeDistance) {
        // Stores which nodes can be visited by pesho, by the police and the path to them
        int * pesho, * police, * from;
        initArrays(map->vertexCount, &pesho, &police, &from);    

        // Finds the safe nodes from the graph
        findSafeNodes(map, startingPoint, pesho, police, from, policeDistance, peshoDistance);

        // Prints out the path from the starting point to the first safe node encountered
        int result = printPath(map->vertexCount, pesho, police, from);

        // Releases the allocated memory
        free(pesho);
        free(police);
        free(from);

        if(result) return;
    }

    // Outputs a message if there are no safe routes
    printf("\nNo safe nodes were found.");
}



// int main() {
//     // Graph * map = initGraph(6);

//     // addEdge(map, 0, 4, 3);
//     // addEdge(map, 0, 5, 3);
//     // addEdge(map, 0, 1, 1);

//     // addEdge(map, 1, 4, 4);
//     // addEdge(map, 1, 3, 4);
//     // addEdge(map, 1, 5, 4);

//     // addEdge(map, 2, 4, 3);

//     // addEdge(map, 4, 5, 2);

//     // printGraph(map);

//     Graph * map = initGraph(5);

//     addEdge(map, 0, 1, 4);

//     addEdge(map, 1, 2, 5);
//     addEdge(map, 1, 3, 2);

//     addEdge(map, 2, 4, 3);

//     addEdge(map, 3, 4, 3);

//     findPath(map, 2, 3, 5);
    
//     return 0;
// }