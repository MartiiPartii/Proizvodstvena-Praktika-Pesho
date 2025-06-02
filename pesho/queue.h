#ifndef QUEUE_H
#define QUEUE_H

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