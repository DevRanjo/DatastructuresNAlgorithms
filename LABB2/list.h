#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

typedef struct List List;
typedef struct Node Node;

void initList(List* L);
bool isEmpty(List* L);
void insert(List* L, Node* N);
Node* search(List* L, int k);
void deleteNode(List* L, Node* N);
Node* max(List* L);
Node* min(List* L);
Node* successor(List* L, Node* N);
Node* predeccessor(List* L, Node* N);

#endif
