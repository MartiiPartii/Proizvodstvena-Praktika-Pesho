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
    double **adjMatrix;

} Graph;

Graph *initGraph(int vertexCount);

void addEdgeDirectional(Graph *graph, int from, int to, double weight);

void addEdge(Graph *graph, int vertex1, int vertex2, double weight);

void printGraph(Graph *graph);

void releaseGraph(Graph *graph);

#endif