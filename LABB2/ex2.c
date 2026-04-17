#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <assert.h> 

int main(){

    List L1, L2; //create two lists
    
    initList(&L1); //send in the adresses to point to the specified lists
    initList(&L2);

    int L1_values[] = {3, 1, 5, 10, 8, 7};
    int L2_values[] = {5, 2, 9, 6, 1, 2};

    int L1_length = sizeof(L1_values)/ sizeof(L1_values[0]);
    int L2_length = sizeof(L2_values)/ sizeof(L2_values[0]);
    printf("L1 size: %d\n", L1_length);

    for(int i=0; i< L1_length; i++){
        Node* node = (Node*)malloc(sizeof(Node));
        node->key = L1_values[i];
        insert(&L1, node);
    }

    for(int i=0; i< L2_length; i++){
        Node* node = (Node*)malloc(sizeof(Node));
        node->key = L2_values[i];
        insert(&L2, node);
    }

    //Minimum and maximum of L1
    Node* maxNodeL1 = max(&L1); 
    Node* minNodeL1 = min(&L1);
    assert(maxNodeL1->key == 10);
    assert(minNodeL1->key == 1);

    //Maximum and minimum of L2
    Node* maxNodeL2 = max(&L2);
    Node* minNodeL2 = min(&L2);
    assert(maxNodeL2->key == 9);
    assert(minNodeL2->key == 1);

    //Successor and predecessor of node with key 5 in L1
    Node* successorL1 = successor(&L1, search(&L1, 5));
    Node* predecessorL1 = predecessor(&L1, search(&L1, 5));
    assert(successor != NULL);
    assert(successorL1->key == 7);
    assert(predecessorL1->key == 3);
    
    //Successor and predeccessor of node with key 9 in L2
    Node* successorL2 = successor(&L2, search(&L2, 9));
    Node* predecessorL2 = predecessor(&L2, search(&L2, 9)); 
    assert(successorL2 == NULL);            //there is no larger value than 9 in list
    assert(predecessorL2->key == 6);

    deleteNode(&L2, search(&L2, 9));
    assert(search(&L2, 9)==NULL);
    
    freeList(&L1);
    freeList(&L2);
    printf("finished\n");
    return 1;
}
