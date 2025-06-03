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
    int platformsCount = 0;
    char *fileName = malloc(sizeof(char) * MAX_PATH_LENGTH);
    ALLOC_ERR(fileName);

    do {
        printf("\nHow many steps is Pesho's jump: ");
        scanf("%d", &peshoSteps);
        if(peshoSteps < 0) printf("\nPlease enter a non negative number.");
    } while(peshoSteps < 0);

    do {
        printf("How many steps can the police jump: ");
        scanf("%d", &policeJump);
        if(policeJump < 0) printf("\nPlease enter a non negative number.");
    } while(policeJump < 0);

    getchar();
    printf("Enter file's path: ");
    fgets(fileName, MAX_PATH_LENGTH, stdin);
    for(int i = 0; i < MAX_PATH_LENGTH; i++) {
        if(fileName[i] == '\n') fileName[i] = '\0';
    }

    printf("From wich platform do you want Pesho to start: ");
    scanf("%d", &start);
    printf("\nStart: %d", start);

    printf("\n%d %s", peshoSteps, fileName);

    Graph *map = createGraph(fileName, platformsCount, peshoSteps);
    findPath(map, start, policeJump, peshoSteps);

    releaseGraph(map);
    free(fileName);
}