#include <stdlib.h>
#include <stdio.h>
#include "stackList.h"


Stack* createStack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value){
    Node* node = malloc(sizeof(Node));
    node->data = value;
    node->next = stack->top; //the last top sets below the new node --sv:den tidigare top blir under den nya noden
    stack->top = node;       //set new node as top
}

int pop(Stack* stack){
    if(stack->top == NULL){return -1;}
    
    Node* tmp = stack->top;
    int value = tmp->data;
    stack->top = tmp->next; //the new top is the node under current
    free(tmp);
    return value;  
}

int isEmpty(Stack* stack){
    return stack->top == NULL;
}

void freeStack(Stack* stack){
    while(!isEmpty(stack)){
        pop(stack);
    }
    free(stack);
}

void freeStack(Stack* stack) {
    if (stack == NULL) return;

    Node* current = stack->top;

    // Free all nodes
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    // Free the stack struct itself
    free(stack);
}

