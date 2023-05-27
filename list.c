#include <stdio.h>
#include <stdlib.h>
#include "list.h"

NodeLIST *createNodeList(int givenKey) {
    NodeLIST *node = malloc(sizeof(NodeLIST));

    if (node == NULL) {
        printf("Couldn't allocate memory!");
        return NULL;
    }

    node->key = givenKey;
    node->next = NULL;

    return node;
}

LIST createList() {
    LIST list;

    list.first = NULL;
    list.last = NULL;

    return list;
}

void insertFirst(LIST *list, int givenKey) {
    NodeLIST *node = createNodeList(givenKey);

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        return;
    }

    node->next = list->first;
    list->first = node;
}

void insertLast(LIST *list, int givenKey) {
    NodeLIST *node = createNodeList(givenKey);

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        return;
    }

    list->last->next = node;
    list->last = node;
}

NodeLIST *search(LIST list, int givenKey) {
    NodeLIST *current = list.first;

    while (current != NULL) {
        if (current->key == givenKey)
            return current;

        current = current->next;
    }
}

void printList(LIST list) {
    NodeLIST *current = list.first;

    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
}
