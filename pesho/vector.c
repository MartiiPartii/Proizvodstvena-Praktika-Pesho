#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector * initVector(int initialCapacity) {
    Vector * vector = (Vector *) malloc(sizeof(Vector));
    ALLOC_ERR(vector)

    vector->buffer = (VectorType *) calloc(initialCapacity, sizeof(VectorType));
    ALLOC_ERR(vector->buffer);

    vector->capacity = initialCapacity;
    vector->size = 0;

    return vector;
}



static void resizeVector(Vector * vector, float factor) {
    vector->buffer = realloc(vector->buffer, sizeof(VectorType) * (float) vector->capacity * factor);
    ALLOC_ERR(vector->buffer);
    vector->capacity *= factor;
}


void pushBackVector(Vector * vector, VectorType val) {
    if(vector->size + 1 >= vector->capacity) resizeVector(vector, 2);
    vector->buffer[vector->size++] = val;
}



VectorType popFrontVector(Vector * vector) {
    VectorType result = vector->buffer[0];

    for(int i = 0; i < vector->size - 1; i++) {
        vector->buffer[i] = vector->buffer[i + 1];
    }

    vector->size--;

    if(vector->size <= vector->capacity / 2) resizeVector(vector, 0.5);

    return result;
}



void printVector(Vector * vector) {
    printf("\n");
    for(int i = 0; i < vector->size; i++) {
        printf("%d ", vector->buffer[i]);
    }
    printf("\n");
}



void releaseVector(Vector * vector) {
    free(vector->buffer);
    free(vector);
}



// int main() {
//     Vector * Vector = initVector(2);
//     pushVector(Vector, 2);
//     pushVector(Vector, 8);
//     pushVector(Vector, 4);
//     pushVector(Vector, 3);
//     popVector(Vector);
//     printVector(Vector);
//     free(Vector);

//     return 0;
// }