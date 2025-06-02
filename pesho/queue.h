#ifndef QUEUE_H
#define QUEUE_H
#include "vector.h"

typedef VectorType QueueType;
typedef Vector Queue;

Queue * initQueue(int initialCapacity);
void pushQueue(Queue * queue, QueueType val);
QueueType popQueue(Queue * Queue);
void printQueue(Queue * Queue);
void releaseQueue(Queue * Queue);

#endif