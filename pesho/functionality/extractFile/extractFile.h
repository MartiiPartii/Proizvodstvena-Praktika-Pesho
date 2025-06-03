#ifndef EXTRACT_H
#define EXTRACT_H
#include "../../dataStructures/graph/graph.h"

// struct for each platform's coordinates and length
typedef struct Platform
{
    int x;
    int y;
    int length;
    int val;
} Platform;

// function to find the coordinates of a platform
Platform *findCoordinates(const char *name, int *platformsCount);

// Functions to find the shortest path
int findMinX(int startI, int startJ, int lengthI, int lengthJ);

// Exporting to file to graph
Graph *createGraph(const char *name, Platform *platforms, int platformsCount, int peshoSteps);

#endif