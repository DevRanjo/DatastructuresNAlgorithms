#ifndef QUEUELIST_H
#define QUEUELIST_H

typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear; 
}Queue; 

Queue* createQueue();
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void printQueue(Queue *q);

#endif
