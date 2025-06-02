#ifndef QUEUE_H
#define QUEUE_H

#define ALLOC_ERR(PTR) if(PTR == NULL) { \
    printf("\nError allocating memory."); \
    exit(1); \
}

typedef int QueueType;

typedef struct Queue {
    QueueType * buffer;
    int size;
    int capacity;
} Queue;

Queue * initQueue(int initialCapacity);
void pushQueue(Queue * queue, QueueType val);
QueueType popQueue(Queue * queue);
void printQueue(Queue * queue);
void releaseQueue(Queue * queue);

#endif