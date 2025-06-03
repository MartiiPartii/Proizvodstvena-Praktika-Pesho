#include <stdio.h>
#include <stdlib.h>
#define MAX_PATH_LENGTH 500
#include "errorHandle.h"
#include "findPath.h"
#include "extractFile.h"

int main()
{
    int peshoSteps = 0;
    char *fileName = malloc(sizeof(char) * MAX_PATH_LENGTH);

    printf("How many steps is Pesho's jump: ");
    scanf("%d", &peshoSteps);

    getchar();
    printf("Enter file's path: ");
    fgets(fileName, MAX_PATH_LENGTH, stdin);

    printf("%d %s", peshoSteps, fileName);
}