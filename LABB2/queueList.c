#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueList.h"

Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL; 
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q){
    return q->front == NULL; //returns true if empty
}

void enqueue(Queue* q, int value){
    Node* newNode = malloc(sizeof(Node));   //create new node to add to queue
    newNode->data = value;
    newNode->next = NULL;
    if(q->front == NULL){                   //if queue is empty
        q->front = newNode;
        q->rear = newNode;
    }
    else{                                   //otherwise add to the end of queue
        q->rear->next = newNode;            //links to the end of queue
        q->rear = newNode;                  //update rear pointer to point at newNode
    }
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is not empty");
        return -1;
    }
    else{
        Node* current = q->front; 
        int value = current->data; //retrieve data from front node
        q->front = q->front->next; //move front pointer to next node
        if(q->front == NULL){      //if queue is empty then rear pointer is =NULL
            q->rear == NULL;
        }
        free(current);
        return value; //return the node removed value
    }
}

// prints every elements in queue
void printQueue(Queue *q) {
    Node* current = q->front; // begins front of the queue
    printf("Queue: ");
    while (current != NULL) {      // goes through the whole queue 
        printf("%d ", current->data); // prints data of current node
        current = current->next;          // goes to next node
    }
    printf("\n");
}

