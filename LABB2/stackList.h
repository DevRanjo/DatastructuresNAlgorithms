#ifndef STACKLIST_H
#define STACKLIST_H

typedef struct stackNode{
    int data;
    Node* next; 
}Node;

typedef struct stackTop{
    Node* top;
}Stack;

Stack* createStack();
void push(Stack* stack, int value);
int pop(Stack* stack);
int isEmpty(Stack* stack);
void freeStack(Stack* stack);

#endif