#pragma once
#include <stdbool.h>

typedef struct NodeSTACK{
    int key;
    struct NodeSTACK *next;
}NodeSTACK;

typedef struct STACK{
    struct NodeSTACK *top;
    struct NodeSTACK *bottom;
    int size;
}STACK;

NodeSTACK* createNodeStack(int givenKey);

STACK createSTACK();

void push(STACK* stack, int givenKey);

void pop(STACK *stack);

void printStack(STACK stack);

bool isEmptyStack(STACK stack);