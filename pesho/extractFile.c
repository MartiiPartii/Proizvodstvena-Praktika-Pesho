#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <math.h>

// struct for each platform's coordinates and length
typedef struct Platform
{
    int x;
    int y;
    int length;
    int val;
} Platform;

// function to find the coordinates of a platform
Platform *findCoordinates(const char *name, int *platformsCount)
{

    FILE *file = fopen(name, "r");
    int s;
    // x and y of the file
    int currRow = 1, currColumn = 1, startColumn = 1;

    // array of platforms to store each platform's info
    int length = 0, count = 0, capacity = 10;
    // int *platforms = (int *)malloc(sizeof(int) * capacity);
    Platform *platforms = malloc(sizeof(Platform) * capacity);

    while ((s = fgetc(file)) != EOF)
    {

        // count the length of the platform
        if (s == '#')
        {
            if (length == 0)
                startColumn = currColumn;
            length++;
        }

        else
        {
            if (length > 0)
            {
                if (*platformsCount == capacity)
                {
                    capacity *= 2;
                    platforms = realloc(platforms, sizeof(Platform) * capacity);
                }

                // Adding info to the platform
                platforms[count].val = count;
                platforms[count].length = length;
                platforms[count].x = startColumn;
                platforms[count].y = currRow;

                // Encreasing the count of the platforms and resetting the length for the new platform
                count++;
                length = 0;
            }

            // Resetting the coordinates in the file
            if (s == '\n')
            {
                currRow++;
                currColumn = 1;
                continue;
            }
        }

        currColumn++;
    }

    // If the loop stopped on a platform here we add its info
    if (length > 0)
    {
        if (*platformsCount == capacity)
        {
            capacity *= 2;
            platforms = realloc(platforms, sizeof(int) * capacity);
        }
        platforms[count].val = count;
        platforms[count].length = length;
        platforms[count].x = startColumn;
        platforms[count].y = currRow;
    }

    fclose(file);

    for (int i = 0; i < count; i++)
    {
        printf("\n%d platform x: %d, y: %d, and is %d long", i, platforms[i].x, platforms[i].y, platforms[i].length);
    }
    printf("\n");

    // Sending the count
    *platformsCount = count;
    return platforms;
}

// Functions to find the shortest path
int findMinX(int startI, int startJ, int lengthI, int lengthJ)
{
    int min = abs(startI - startJ);
    int X;
    int Xi = startI, Xj = startJ;

    for (int k = 0; k < lengthI; k++)
    {
        for (int l = 0; l < lengthJ; l++)
        {
            X = abs(Xi - Xj);
            if (X < min)
                min = X;
            Xj++;
        }
        Xi++;
        Xj = startJ;
    }

    return min;
}

// Exporting to file to graph
Graph *createGraph(const char *name, Platform *platforms, int platformsCount, int peshoSteps)
{
    FILE *file = fopen(name, "r");
    int s;
    while ((s = fgetc(file)) != EOF)
    {
        if (s == '#')
            break;
    }

    Graph *map = initGraph(platformsCount);
    int X;

    for (int i = 0; i < platformsCount; i++)
    {
        for (int j = 0; j < platformsCount; j++)
        {
            X = findMinX(platforms[i].x, platforms[j].x, platforms[i].length, platforms[j].length);
            int Y = abs(platforms[j].y - platforms[i].y);
            double weight = sqrt(pow(X, 2) + pow(Y, 2));

            // If the path from one to other node is more then pesho's steps we dont add edge
            if (weight <= peshoSteps)
                addEdge(map, i, j, weight);
        }
    }

    printGraph(map);

    return map;
}

int main()
{
    const char *fileName = "map.txt";

    int steps = 6;
    int platformsCount;

    Platform *platforms = findCoordinates(fileName, &platformsCount);

    createGraph(fileName, platforms, platformsCount, steps);

    // printGraph(ma/p);
}