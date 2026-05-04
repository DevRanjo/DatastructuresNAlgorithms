#include <stdio.h>
#include "binary_tree.h"
#include <stdlib.h>

int main(){

    Node* tree = create_node(10);
    insert(tree, 8);
    insert(tree, 12);
    insert(tree, 5);

    display_tree(tree);
    printf("\nYour tree sorted: "); 
    inorder_tree_walk(tree);
    printf("\n");
    min(tree);
    max(tree);

    /*successor(tree, 8);
    successor(tree, 5);
    successor(tree, 12);

    //predecessor(tree, 8);
    //predecessor(tree, 12);
    //predecessor(tree, 5);

    /*printf("The size of your tree is %d \n", size_of_tree(tree));
    printf("The depth of your tree is %d \n", depth_of_tree(tree));

    printf("Your tree sorted: "); 
    SortingPrint(tree);
    printf("\n");

    const char *filename = "../Lab3/sorting_problems/test-10-1-problem"; 
    int *array = load_file(filename);
    int n = array[0];
    

    printf("Array before sorting: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", array[i]);
    }

    Node* tree2 = createNode(array[1]);
    for (int i = 2; i <= n; i++) {
        insert(tree2, array[i]);
    }
    /* display_tree(tree2); 

    printf("\nYour tree (array) sorted: "); 
    SortingPrint(tree2);
    printf("\n");*/


    Testing();
    free_tree(tree);

    return 0;
}