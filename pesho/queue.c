#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue * initQueue(int initialCapacity) {
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    ALLOC_ERR(queue)

    queue->buffer = (QueueType *) calloc(initialCapacity, sizeof(QueueType));
    ALLOC_ERR(queue->buffer);

    queue->capacity = initialCapacity;
    queue->size = 0;

    return queue;
}



static void resizeQueue(Queue * queue, float factor) {
    queue->buffer = realloc(queue->buffer, sizeof(QueueType) * (float) queue->capacity * factor);
    ALLOC_ERR(queue->buffer);
    queue->capacity *= factor;
}


void pushQueue(Queue * queue, QueueType val) {
    if(queue->size >= queue->capacity) resizeQueue(queue, 2);
    queue->buffer[queue->size++] = val;
}



QueueType popQueue(Queue * queue) {
    QueueType result = queue->buffer[0];

    for(int i = 0; i < queue->size - 1; i++) {
        queue->buffer[i] = queue->buffer[i + 1];
    }

    queue->size--;

    if(queue->size <= queue->capacity / 2) resizeQueue(queue, 0.5);

    return result;
}



void printQueue(Queue * queue) {
    printf("\n");
    for(int i = 0; i < queue->size; i++) {
        printf("%d ", queue->buffer[i]);
    }
    printf("\n");
}



void releaseQueue(Queue * queue) {
    free(queue->buffer);
    free(queue);
}



int main() {
    Queue * queue = initQueue(2);
    pushQueue(queue, 2);
    pushQueue(queue, 8);
    pushQueue(queue, 4);
    pushQueue(queue, 3);
    popQueue(queue);
    printQueue(queue);
    free(queue);

    return 0;
}