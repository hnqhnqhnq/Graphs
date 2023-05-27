#pragma once

#include "list.h"

enum {
    VISITED,
    NOTVISITED
};

typedef struct GRAPH_AM {
    int numberOfNodes;
    int **adjMatrix;
} GRAPH_AM;

GRAPH_AM createGraphAdjMatrix(FILE *file);

void bfsAdjMatrix(GRAPH_AM graph, int sourceNode);

void dfsAdjMatrix(GRAPH_AM graph, int sourceNode);

void dfsAdjMatrixRecursive(GRAPH_AM graph, int sourceNode, int visited[]);

typedef struct GRAPH_DL {
    int numberOfNodes;
    LIST *dynamicList;
} GRAPH_DL;

GRAPH_DL createGraphDynamicList(FILE *file);

void bfsDynamicList(GRAPH_DL graph, int sourceNode);

void dfsDynamicList(GRAPH_DL graph, int sourceNode);

void dfsDynamicListRecursive(GRAPH_DL graph, int sourceNode, int visited[]);
