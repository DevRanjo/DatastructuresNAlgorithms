#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/*Implement a double-linked list with a sentinel of integers and provide all of the dynamic set operations 
listed below. (Yes, it has to be a double-linked list, and it has to be with a sentinel.) For additional 
information check CLRS3 page 230 or CLRS4 page 250*/


void initList(List* L){        //initialize list

    L->sentinel = (Node*)malloc(sizeof(Node)); //point to allocate memory in size of node
    L->sentinel->prev = L->sentinel;
    L->sentinel->next = L->sentinel;
    return;
}

bool isEmpty(List* L){
    return L->sentinel->next == L->sentinel;
} //if empty the node points at itself

void insert(List* L, Node* N){
    if(N==NULL){ return;} //if N is NUll return and do nothing

    Node* last = L->sentinel->prev; //sentinel previous points to last node
    last->next = N;                 //put next last node point to be insert new node
    
    N->prev = last;
    N->next = L->sentinel; //new node point to sentinel
    
    L->sentinel->prev = N; //update sentinel
    return;
}

Node* search(List* L, int k){ //key is the value we look for
    
    Node* current = L->sentinel->next; //start from first node
    
    while(current != L->sentinel){ //traverse list -> until sentinel
        if(current->key == k){
            return current;
        }
        current = current->next;
    }
    return NULL; //not found
}

Node* deleteNode(List* L, Node* N){
    if(N==NULL || N == L->sentinel){ return NULL;} 
    Node* tmp = N;

    N->prev->next = N->next;
    N->next->prev = N->prev;

    if((tmp->next != N->prev) && (tmp->prev != N->prev)){return N;} //return pointer to deleted node from list
    else{ return NULL;}
}

Node* max(List* L){
    Node* current = L->sentinel->next; //first node

    if(current == L->sentinel){ return NULL;} //list empty

    Node* maxNode = current;
    while(current != L->sentinel){

        if(current->key > maxNode->key){
            maxNode = current;
        }
        current = current->next;
    }
    return maxNode;
}

Node* min(List* L){
    Node* current = L->sentinel->next; //startnode
    if(current == L->sentinel){ return NULL;} //if point at self -> empty list

    Node* minNode = current;
    while(current != L->sentinel){

        if(current->key < minNode->key){
            minNode = current;
        }
        current = current->next;
    }
    return minNode;
}

Node* successor(List* L, Node* N){ //find node that is exactly the node larger than N

    Node* current = L->sentinel->next; //start
    Node* successor = NULL;

    while(current != L->sentinel){
        if(current->key > N->key){
            if(successor == NULL || current->key < successor->key){ //söka igenom spannet mellan N-key> och <successor->key
                successor = current;} //uppdatera successor (spannet blir mindre)
        }
        current = current->next;
    }

    return successor;
}

Node* predecessor(List* L, Node* N){
    Node* current = L->sentinel->next;
    Node* predecessor = NULL;

    while(current != L->sentinel){
        if(current->key < N->key){
            if(predecessor == NULL || current->key > predecessor->key){ //predecessor mindre än N->key och större än alla curr->key
                predecessor = current;
            }
        }
        current = current->next;
    }
    return predecessor;
}

void freeList(List* L){
    if (L == NULL || L->sentinel == NULL) return;

    Node* current = L->sentinel->next;

    // Traverse and free all nodes except sentinel
    while (current != L->sentinel) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    // Free the sentinel node
    free(L->sentinel);
    L->sentinel = NULL;
}




