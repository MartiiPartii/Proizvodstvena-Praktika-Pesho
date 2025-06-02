#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <math.h>

typedef struct Platform
{
    int x;
    int y;
    int length;
    int val;
} Platform;

Platform *findCoordinates(const char *name, int *platformsCount)
{

    FILE *file = fopen(name, "r");
    int s;
    // x and y of the file
    int currRow = 1, currColumn = 1, startColumn = 1;

    // array of platforms of the platforms
    int length = 0, i = 0, count = 0, capacity = 10;
    // int *platforms = (int *)malloc(sizeof(int) * capacity);
    Platform *platforms = malloc(sizeof(Platform) * capacity);

    while ((s = fgetc(file)) != EOF)
    {
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
                platforms[count].val = count;
                platforms[count].length = length;
                platforms[count].x = startColumn;
                platforms[count].y = currRow;
                count++;
                length = 0;
            }

            if (s == '\n')
            {
                currRow++;
                currColumn = 1;
                continue;
            }
        }

        currColumn++;
    }

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

    *platformsCount = count;
    return platforms;
}

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

Graph *findEdgesWeight(const char *name, Platform *platforms, int platformsCount, int peshoSteps)
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

    findEdgesWeight(fileName, platforms, platformsCount, steps);

    // printGraph(ma/p);
}