#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

typedef struct Node{
    int key;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct List{
    Node* sentinel;
}List;

void initList(List* L);
bool isEmpty(List* L);
void insert(List* L, Node* N);
Node* search(List* L, int k);
Node* deleteNode(List* L, Node* N);
Node* max(List* L);
Node* min(List* L);
Node* successor(List* L, Node* N);
Node* predecessor(List* L, Node* N);
void freeList(List* L);

#endif
