#include <stdio.h>
#include <stdlib.h>
#define MAX_PATH_LENGTH 500
#include "errorHandle.h"
#include "./functionality/findPath/findPath.h"
#include "./functionality/extractFile/extractFile.h"
#include "./dataStructures/graph/graph.h"
#include "./dataStructures/vector/vector.h"

int main()
{
    int peshoSteps = 0, start = 0, policeJump = 0;
    int platformsCount;
    char *fileName = malloc(sizeof(char) * MAX_PATH_LENGTH);
    ALLOC_ERR(fileName);

    printf("How many steps is Pesho's jump: ");
    scanf("%d", &peshoSteps);

    printf("How many steps can the police jump: ");
    scanf("%d", &policeJump);

    getchar();
    printf("Enter file's path: ");
    fgets(fileName, MAX_PATH_LENGTH, stdin);

    printf("From wich platform do you want Pesho to start: ");
    scanf("%d", &start);
    printf("\nStart: %d", start);

    printf("\n%d %s", peshoSteps, fileName);

    Graph *map = createGraph(fileName, platformsCount, peshoSteps);
    findPath(map, start, policeJump, peshoSteps);

    releaseGraph(map);
    free(fileName);
}