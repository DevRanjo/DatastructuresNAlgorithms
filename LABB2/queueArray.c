#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

typedef struct ArrayQueue{
    int queue[SIZE];        //q will have index from 0 to 19
    int head;               //index newest element
    int tail;               //index last element
}Queue;

Queue* createQueue(){
    Queue* q;
    q->head = 0;
    q->tail = 0;
    return q; 
}

bool isEmpty(Queue* q){
    if(q->head==q->tail){return true;} //if both indexes are 0 then queue is empty
    else{return false;}
}

void enqueue(Queue* q, int data){
    if((q->head+1) % SIZE == q->head){ //if ex 19+1/20 gives r=0 <- head index
        printf("Queue is full\n");
        return;
    }
    q->queue[q->tail] = data; //add data at the last index of queue
    q->tail = (q->tail+1) % SIZE; //update tail index. Wraps around if there is array overflow 
}

bool dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return false;
    }
    int data = q->queue[q->head]; //save the value of the first element in queue
    q->head = (q->head+1) % SIZE; //move head pointer to next index (next element in queue)
    //if overflow->wrap arount in a circular manner
    return data;
}
