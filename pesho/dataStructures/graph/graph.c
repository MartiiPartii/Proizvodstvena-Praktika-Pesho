#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "../../errorHandle.h"

// init graph
Graph *initGraph(int vertexCount)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    ALLOC_ERR(graph);
    graph->vertexCount = vertexCount;
    graph->adjMatrix = (int **)malloc(sizeof(int *) * vertexCount);
    ALLOC_ERR(graph->adjMatrix);

    for (int i = 0; i < vertexCount; i++)
    {
        graph->adjMatrix[i] = (int *)calloc(vertexCount, sizeof(int));
        ALLOC_ERR(graph->adjMatrix[i])
    }

    return graph;
}

// add Graph

void addEdgeDirectional(Graph *graph, int from, int to, int weight)
{
    graph->adjMatrix[from][to] = weight;
}

void addEdge(Graph *graph, int vertex1, int vertex2, int weight)
{
    addEdgeDirectional(graph, vertex1, vertex2, weight);
    addEdgeDirectional(graph, vertex2, vertex1, weight);
}

// print Graph

void printGraph(Graph *graph)
{
    printf("# |");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        printf("%d ", i);
    }
    printf("\n--|");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < graph->vertexCount; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// release Graph
void releaseGraph(Graph *graph)
{

    for (int i = 0; i < graph->vertexCount; i++)
    {
        free(graph->adjMatrix[i]);
    }

    free(graph->adjMatrix);
    free(graph);
}