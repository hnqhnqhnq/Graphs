#pragma once

typedef struct NodeLIST {
    int key;
    struct NodeLIST *next;
} NodeLIST;

typedef struct LIST {
    struct NodeLIST *first;
    struct NodeLIST *last;
} LIST;

NodeLIST *createNodeList(int givenKey);

LIST createList();

void insertFirst(LIST *list, int givenKey);

void insertLast(LIST *list, int givenKey);

NodeLIST *search(LIST list, int givenKey);

void printList(LIST list);