#ifndef GRAPH_H
#define GRAPH_H

typedef struct Node
{
    int length;
    int val;
} Node;

typedef struct Graph
{
    int vertexCount;
    int **adjMatrix;

} Graph;

Graph *initGraph(int vertexCount);

void addEdgeDirectional(Graph *graph, int from, int to, int weight);

void addEdge(Graph *graph, int vertex1, int vertex2, int weight);

void printGraph(Graph *graph);

#endif