#ifndef ERROR_H
#define ERROR_H

#define ALLOC_ERR(PTR) if(PTR == NULL) { \
    printf("\nError allocating memory.\n"); \
    exit(1); \
}

#endif