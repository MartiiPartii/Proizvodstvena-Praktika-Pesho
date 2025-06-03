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
    graph->adjMatrix = (double **)malloc(sizeof(double *) * vertexCount);
    ALLOC_ERR(graph->adjMatrix);

    for (int i = 0; i < vertexCount; i++)
    {
        graph->adjMatrix[i] = (double *)calloc(vertexCount, sizeof(double));
        ALLOC_ERR(graph->adjMatrix[i])
    }

    return graph;
}

// add Graph

void addEdgeDirectional(Graph *graph, int from, int to, double weight)
{
    graph->adjMatrix[from][to] = weight;
}

void addEdge(Graph *graph, int vertex1, int vertex2, double weight)
{
    // printf("\nWeight: %f", weight);
    addEdgeDirectional(graph, vertex1, vertex2, weight);
    addEdgeDirectional(graph, vertex2, vertex1, weight);
}

// print Graph

void printGraph(Graph *graph)
{
    printf("# |");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        printf("%4d ", i);
    }
    printf("\n--|");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        printf("-----");
    }
    printf("\n");
    for (int i = 0; i < graph->vertexCount; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < graph->vertexCount; j++)
        {
            printf("%2.2f ", graph->adjMatrix[i][j]);
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