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
    int count;
} Platform;

Platform *findCoordinates(const char *name)
{

    FILE *file = fopen(name, "r");
    int s;
    // x and y of the file
    int currRow = 1, currColumn = 1, startColumn = 1;

    // array of platforms of the platforms
    int length = 0, i = 0, capacity = 10;
    // int *platforms = (int *)malloc(sizeof(int) * capacity);
    Platform *platforms = malloc(sizeof(Platform) * capacity);

    platforms->count = 0;

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
                if (platforms->count == capacity)
                {
                    capacity *= 2;
                    platforms = realloc(platforms, sizeof(Platform) * capacity);
                }
                platforms[platforms->count].val = platforms->count;
                platforms[platforms->count].length = length;
                platforms[platforms->count].x = startColumn;
                platforms[platforms->count].y = currRow;
                platforms->count++;
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
        if (platforms->count == capacity)
        {
            capacity *= 2;
            platforms = realloc(platforms, sizeof(int) * capacity);
        }
        platforms[platforms->count].val = platforms->count;
        platforms[platforms->count].length = length;
        platforms[platforms->count].x = startColumn;
        platforms[platforms->count].y = currRow;
    }

    fclose(file);

    for (int i = 0; i < platforms->count; i++)
    {
        printf("\n%d platform x: %d, y: %d, and is %d long", i, platforms[i].x, platforms[i].y, platforms[i].length);
    }

    return platforms;
}

int findEdgesWeight(const char *name, Platform *platforms, int peshoSteps)
{
    FILE *file = fopen(name, "r");
    int s;
    while ((s = fgetc(file)) != EOF)
    {
        if (s == "#")
            break;
    }

    Graph *map;
    initGraph(platforms->count);

    for (int i = 0; i < platforms->count; i++)
    {
        for (int j = 0; j < platforms->count; j++)
        {
            int X = abs(platforms[i].x - platforms[j].x);
            int Y = abs(platforms[j].y - platforms[i].y);
            int weight = sqrt(pow(X, 2) + pow(Y, 2));
            addEdge(map, i, j, weight);
        }
    }
}

int main()
{
    const char *fileName = "map.txt";
    Platform *platforms;
    int steps = 5;

    platforms = findCoordinates(fileName);
    findEdgesWeight(fileName, platforms, steps);
}