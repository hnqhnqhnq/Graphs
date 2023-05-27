#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
#include "list.h"
#include "stack.h"

GRAPH_AM createGraphAdjMatrix(FILE *file) {
    GRAPH_AM graph;

    fscanf(file, "%d", &graph.numberOfNodes);

    graph.numberOfNodes++;

    graph.adjMatrix = (int **) calloc(graph.numberOfNodes, sizeof(int *));
    for (int i = 1; i < graph.numberOfNodes; i++)
        graph.adjMatrix[i] = (int *) calloc(graph.numberOfNodes, sizeof(int));

    int firstEdge;
    int secondEdge;

    while (fscanf(file, "%d %d", &firstEdge, &secondEdge) == 2) {
        graph.adjMatrix[firstEdge][secondEdge] = 1;
    }

    return graph;
}

void bfsAdjMatrix(GRAPH_AM graph, int sourceNode) {
    int visited[graph.numberOfNodes];
    int currentNode;
    int bfsNode;
    QUEUE queue = createQueue();

    for (int i = 1; i < graph.numberOfNodes; i++)
        visited[i] = NOTVISITED;

    visited[sourceNode] = VISITED;
    enqueue(&queue, sourceNode);

    while (!isEmptyQueue(queue)) {
        currentNode = queue.head->key;
        printf("visited: %d\n", currentNode);
        dequeue(&queue);

        for (bfsNode = 1; bfsNode < graph.numberOfNodes; bfsNode++) {
            if (graph.adjMatrix[currentNode][bfsNode] == 1)
                if (visited[bfsNode] == NOTVISITED) {
                    visited[bfsNode] = VISITED;
                    enqueue(&queue, bfsNode);
                }
        }
    }
}

void dfsAdjMatrix(GRAPH_AM graph, int sourceNode) {
    int visited[graph.numberOfNodes];
    int currentNode;
    int dfsNode;
    STACK stack = createSTACK();

    for (int i = 1; i < graph.numberOfNodes; i++)
        visited[i] = NOTVISITED;

    visited[sourceNode] = VISITED;
    push(&stack, sourceNode);

    while (!isEmptyStack(stack)) {
        currentNode = stack.top->key;
        printf("visited: %d\n", currentNode);
        pop(&stack);

        for (dfsNode = 1; dfsNode < graph.numberOfNodes; dfsNode++) {
            if (graph.adjMatrix[currentNode][dfsNode] == 1)
                if (visited[dfsNode] == NOTVISITED) {
                    visited[dfsNode] = VISITED;
                    push(&stack, dfsNode);
                }
        }
    }
}

void dfsAdjMatrixRecursive(GRAPH_AM graph, int sourceNode, int visited[]) {
    printf("visited: %d\n", sourceNode);
    visited[sourceNode] = VISITED;

    for (int dfsNode = 1; dfsNode < graph.numberOfNodes; dfsNode++) {
        if (graph.adjMatrix[sourceNode][dfsNode] == 1 && visited[dfsNode] == NOTVISITED) {
            dfsAdjMatrixRecursive(graph, dfsNode, visited);
        }
    }
}

GRAPH_DL createGraphDynamicList(FILE *file) {
    GRAPH_DL graph;

    fscanf(file, "%d", &graph.numberOfNodes);

    graph.numberOfNodes++;

    graph.dynamicList = (LIST *) calloc(graph.numberOfNodes, sizeof(LIST));
    for (int i = 1; i < graph.numberOfNodes; i++)
        graph.dynamicList[i] = createList();

    int firstEdge;
    int secondEdge;

    while (fscanf(file, "%d %d", &firstEdge, &secondEdge) == 2)
        insertLast(&graph.dynamicList[firstEdge], secondEdge);

    return graph;
}

void bfsDynamicList(GRAPH_DL graph, int sourceNode) {
    int visited[graph.numberOfNodes];
    int currentNode;
    int bfsNode;
    QUEUE queue = createQueue();

    for (int i = 1; i < graph.numberOfNodes; i++)
        visited[i] = NOTVISITED;

    visited[sourceNode] = VISITED;
    enqueue(&queue, sourceNode);

    while (!isEmptyQueue(queue)) {
        currentNode = queue.head->key;

        printf("visited: %d\n", currentNode);
        dequeue(&queue);

        NodeLIST *iterate = graph.dynamicList[currentNode].first;
        while (iterate != NULL) {
            bfsNode = iterate->key;

            if (visited[bfsNode] == NOTVISITED) {
                visited[bfsNode] = VISITED;
                enqueue(&queue, bfsNode);
            }

            iterate = iterate->next;
        }
    }
}

void dfsDynamicList(GRAPH_DL graph, int sourceNode) {
    int visited[graph.numberOfNodes];
    int currentNode;
    int dfsNode;
    STACK stack = createSTACK();

    for (int i = 1; i < graph.numberOfNodes; i++)
        visited[i] = NOTVISITED;

    visited[sourceNode] = VISITED;
    push(&stack, sourceNode);

    while (!isEmptyStack(stack)) {
        currentNode = stack.top->key;

        printf("visited: %d\n", currentNode);
        pop(&stack);

        NodeLIST *iterate = graph.dynamicList[currentNode].first;
        while (iterate != NULL) {
            dfsNode = iterate->key;

            if (visited[dfsNode] == NOTVISITED) {
                visited[dfsNode] = VISITED;
                push(&stack, dfsNode);
            }

            iterate = iterate->next;
        }
    }
}

void dfsDynamicListRecursive(GRAPH_DL graph, int sourceNode, int visited[]) {
    printf("visited: %d\n", sourceNode);
    visited[sourceNode] = VISITED;

    NodeLIST *iterate = graph.dynamicList[sourceNode].first;
    while (iterate != NULL) {
        int dfsNode = iterate->key;

        if (visited[dfsNode] == NOTVISITED) {
            visited[dfsNode] = VISITED;
            dfsDynamicListRecursive(graph, dfsNode, visited);
        }

        iterate = iterate->next;
    }
}



