#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "vector.h"

Queue * initQueue(int initialCapacity) {
    return initVector(initialCapacity);
}


void pushQueue(Queue * queue, QueueType val) {
    pushBackVector(queue, val);
}



QueueType popQueue(Queue * queue) {
    return popFrontVector(queue);
}



void printQueue(Queue * queue) {
    printVector(queue);
}



void releaseQueue(Queue * queue) {
    releaseVector(queue);
}



// int main() {
//     Queue * queue = initQueue(2);
//     pushQueue(queue, 2);
//     pushQueue(queue, 8);
//     pushQueue(queue, 4);
//     pushQueue(queue, 3);
//     popQueue(queue);
//     printQueue(queue);
//     free(queue);

//     return 0;
// }