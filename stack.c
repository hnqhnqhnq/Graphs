#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

NodeSTACK *createNodeStack(int givenKey) {
    NodeSTACK *node = malloc(sizeof(NodeSTACK));

    if (node == NULL) {
        printf("Couldn't allocate memory!");
        return NULL;
    }

    node->key = givenKey;
    node->next = NULL;

    return node;
}

STACK createSTACK() {
    STACK stack;

    stack.top = NULL;
    stack.bottom = NULL;
    stack.size = 0;

    return stack;
}

void push(STACK *stack, int givenKey) {
    NodeSTACK *node = createNodeStack(givenKey);

    if (stack->top == NULL) {
        stack->top = node;
        stack->bottom = node;
        stack->size++;
        return;
    }

    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

void pop(STACK *stack) {
    NodeSTACK *current = stack->top;

    if (stack != NULL) {
        stack->top = stack->top->next;
        stack->size--;
        free(current);
    }

    if (stack->top == NULL) {
        stack->bottom = NULL;
        return;
    }

}

void printStack(STACK stack) {
    NodeSTACK *current = stack.top;

    while (current != NULL) {
        printf("%d\n", current->key);
        current = current->next;
    }
}
bool isEmptyStack(STACK stack){
    if(stack.size==0)
        return true;
    return false;
}




