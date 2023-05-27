#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

NodeQUEUE *createNodeQueue(int givenKey) {
    NodeQUEUE *node = malloc(sizeof(NodeQUEUE));

    if (node == NULL) {
        printf("Couldn't allocate memory!");
        return NULL;
    }

    node->key = givenKey;
    node->next = NULL;

    return node;
}

QUEUE createQueue() {
    QUEUE queue;

    queue.size = 0;
    queue.head = NULL;
    queue.tail = NULL;

    return queue;
}

void enqueue(QUEUE *queue, int givenKey) {
    NodeQUEUE *node = createNodeQueue(givenKey);

    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
        queue->size++;
        return;
    }

    queue->tail->next = node;
    queue->tail = node;
    queue->size++;
}

void dequeue(QUEUE *queue) {
    NodeQUEUE *current = queue->head;

    if (queue->head != NULL) {
        queue->head = queue->head->next;
        free(current);
        queue->size--;
    }

    if (queue->head == NULL) {
        queue->tail = NULL;
        return;
    }
}

bool isEmptyQueue(QUEUE queue) {
    if (queue.size == 0)
        return true;

    return false;
}

void printQueue(QUEUE queue) {
    NodeQUEUE *current = queue.head;

    if (queue.head != NULL) {
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->next;
        }
    }
}
