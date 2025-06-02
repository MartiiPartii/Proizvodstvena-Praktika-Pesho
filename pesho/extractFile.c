#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct Platform
{
    int x;
    int y;
    int length;
} Platform;

int *findCoordinates(const char *name)
{

    FILE *file = fopen(name, "r");
    int s;
    // x and y of the file
    int currRow = 1, currColumn = 1, startColumn = 1;

    // array of platforms of the platforms
    int length = 0, i = 0, platformsCount = 0, capacity = 10;
    // int *platforms = (int *)malloc(sizeof(int) * capacity);
    Platform *platforms = malloc(sizeof(Platform) * capacity);

    while ((s = fgetc(file)) != EOF)
    {
        if (s == '#')
        {
            startColumn = currColumn;
            length++;
        }

        else
        {
            if (length > 0)
            {
                if (platformsCount == capacity)
                {
                    capacity *= 2;
                    platforms = realloc(platforms, sizeof(int) * capacity);
                }
                platforms[platformsCount++].length = length;
                platforms[platformsCount++].x = startColumn;
                platforms[platformsCount++].y = currRow;
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
        if (platformsCount == capacity)
        {
            capacity *= 2;
            platforms = realloc(platforms, sizeof(int) * capacity);
        }
        platforms[platformsCount++].length = length;
        platforms[platformsCount++].x = startColumn;
        platforms[platformsCount++].y = currRow;
    }

    fclose(file);

    for (int i = 0; i < platformsCount; i++)
    {
        printf("\n%d platform x: %d, y: %d, and is %d long", platforms[i].x, platforms[i].y, platforms[i].length);
    }

    return platforms;
}

int findEdgesWeight(const char *name, int *platforms)
{
}

int main()
{
    char *fileName = "map.txt";
    int *platforms;

    platforms = findCoordinates(fileName);
    findEdgesWeight(fileName, platforms);
}