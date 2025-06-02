#ifndef VECTOR_H
#define VECTOR_H

#define ALLOC_ERR(PTR) if(PTR == NULL) { \
    printf("\nError allocating memory.\n"); \
    exit(1); \
}

typedef int VectorType;

typedef struct Vector {
    VectorType * buffer;
    int size;
    int capacity;
} Vector;

Vector * initVector(int initialCapacity);
void pushBackVector(Vector * vector, VectorType val);
VectorType popFrontVector(Vector * vector);
VectorType popBackVector(Vector * vector);
void printVector(Vector * vector);
void releaseVector(Vector * vector);

#endif