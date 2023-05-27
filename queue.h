#pragma once

#include <stdbool.h>

typedef struct NodeT {
    int key;
    struct NodeT *next;
} NodeQUEUE;

typedef struct QUEUE {
    int size;
    struct NodeT *head;
    struct NodeT *tail;
} QUEUE;

NodeQUEUE *createNodeQueue(int givenKey);

QUEUE createQueue();

void enqueue(QUEUE *queue, int givenKey);

void dequeue(QUEUE *queue);

bool isEmptyQueue(QUEUE queue);

void printQueue(QUEUE queue);
