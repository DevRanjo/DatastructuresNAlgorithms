#ifndef STACKLIST_H
#define STACKLIST_H

typedef struct stackNode{
    int data;
    Node* next; 
}Node;

typedef struct stackTop{
    Node* top;
}Stack;

#endif