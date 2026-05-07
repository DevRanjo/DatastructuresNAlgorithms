#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_tree.h"


Node* create_node(int key){
    Node* newnode = malloc(sizeof(Node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return NULL;    
    }
    newnode->key = key;
    newnode->right = NULL; 
    newnode->left = NULL; 
    return newnode; 
}

// Here we insert a key value. If tree reaches the end or is empty it creates a new node, if key is smaller than its root it goes right and if its bigger it gos left.
Node* insert(Node* root, int key){
    if(root == NULL){
        return create_node(key); //if tree empty-> return new node as root node
    }
    if(key < root->key ){
        root->left = insert(root->left, key);
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
    }
    return root;
}

//search node with value of input key
Node* search(Node* root, int key){
    if(root == NULL || root->key == key){
        return root; //if tree is empty or key found
    }
    if(key < root->key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

//smallest value at the leftmost bottom node
Node* min(Node* root){
    if(root==NULL){ return NULL; }

    while(root->left != NULL){
        root = root->left;
    }
    return root; 
}

//highest value at the furthest node to the bottom right
Node* max(Node* root){
    if(root==NULL){ return NULL; }

    while(root->right != NULL){
        root = root->right; 
    }
    return root;
}

// We print the values/keys in order from smallest to largest.
void inorder_tree_walk(Node* root){
    if(root!=NULL){
        inorder_tree_walk(root->left);
        printf("%d ", root->key);
        inorder_tree_walk(root->right);
    }
    return;
}

//(1) goes to key node -> goes to the right child -> find min in subtree which is the closest to key but just a little more
Node* successor(Node* root, int key){
    Node* current = root; 
    Node* successor = NULL; 

    //first find node with given key
    while(current!=NULL){

        if(key < current->key){
            successor = current;        // potential successor
            current = current->left; 
        }

        else if(key > current->key){
            current = current->right;
        }
        
        else{   //reaches the right key node
            if(current->right != NULL){
                return min(current->right); 
            }
            break;
        }
    }
    return successor; 
}

//goes to key node -> look at min at right subtree otherwise return 
Node* predecessor(Node* root, int key) {
    Node* current = root;
    Node* predecessor = NULL;

    // find node with the given key
    while(current != NULL) {
        if(key > current->key) {
            predecessor = current;     // potential predecessor
            current = current->right;
        }
        else if(key < current->key) {
            current = current->left;
        }
        else {  // key found
            if(current->left != NULL) {
                return max(current->left);  // max in left subtree
            }
            break;
        }
    }

    return predecessor;  // return ancestor predecessor if no left child
}

//go until reached end of node
Node* delete_node(Node* root, int key){
    if(root == NULL){ return NULL;}

    if(key < root->key){
        root->left = delete_node(root->left, key);
    } 
    else if(key > root->key){
        root->right = delete_node(root->right, key);
    } 
    else {// Node found!

        // if only has right child
        if(root->left == NULL){
            Node* temp = root->right; //saves node value from right below (slightly bigger)
            free(root);              //delete node 
            return temp; //returning tmp to link with parent node of deleted node ex 8->5->7 d(7) 8->7

        } 
        //if only has left child
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        } 
        else {
            // Node with two children
            Node* temp = min(root->right); //finding closest value on right which is min of subtree
            root->key = temp->key;         //copy value up
            root->right = delete_node(root->right, temp->key); //delete duplicate
        }
    }
    return root;
}


void print_space(int level_of_space){
    for(int i=0; i<level_of_space; i++){
        printf("\t");
    }
}

void recursive_print_tree(Node* root, int level){
    if(root==NULL){
        print_space(level);
        printf("---empty---\n");
        return;
    }
    print_space(level);
    printf("value= %d\n", root->key);
    print_space(level);

    printf("Left\n");
    recursive_print_tree(root->left, level+1);
    print_space(level);

    printf("right\n");
    recursive_print_tree(root->right, level+1);
    print_space(level);

    printf("done\n");
}

void display_tree(Node* root){
    recursive_print_tree(root, 0);
}

// Here we free up meomory after using the trees to avoid memory leaks.
void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void Test_delete(){

    // make a tree with nodes
    Node* root = create_node(8);
    insert(root, 5);
    insert(root, 12);
    insert(root, 11);
    insert(root, 15);
    insert(root, 7);
    insert(root, 2);

/*          8      our tree
          /   \
         5    12
        / \   / \
       2  7  11  15 
*/


    // case1 ( dont have children )
    delete_node(root, 2);
    assert(search(root, 2) == NULL);

    // case2 ( right children )
    delete_node(root, 5);
    assert(search(root, 5) == NULL);
    assert(search(root, 7) != NULL); // check is 5 is gone but 7 is still there

    // case3 ( left childen )
    delete_node(root, 15); // puts back
    delete_node(root, 12);
    assert(search(root, 12) == NULL);
    assert(search(root, 11) != NULL);

    // case4 ( if teo children )
    insert(root, 12); 
    insert(root, 15);// puts back

    delete_node(root, 12);
    assert(search(root, 12) == NULL);
    assert(search(root, 11) != NULL);
    assert(search(root, 15) != NULL);


    // case5 ( if root is removed )
    delete_node(root, 8);
    assert(search(root, 8) == NULL); 



    // if given node dont exist
    delete_node(root, 20);
    assert(root != NULL); // root should be gone but not the tree!

    free_tree(root);
    return;

}
void Test_insert(){
    Node* test_root = create_node(10);
    assert(test_root!=NULL);
    assert(test_root->key==10);
    assert(test_root->left==NULL);
    assert(test_root->right==NULL);

    //Testing if smaller value goes left
    test_root = insert(test_root, 5);
    assert(test_root->left->key == 5);
    assert(test_root->right==NULL);

    //Testing if bigger value goes right
    test_root = insert(test_root, 18);
    assert(test_root->right->key == 18);
    assert(test_root->left->key==5);

    //Testing that dublicate won't be added
    test_root = insert(test_root, 10);
    assert(test_root->left->key==5);
    assert(test_root->right->key==18);
    assert(test_root->left->left == NULL);
    assert(test_root->left->right==NULL);
    assert(test_root->right->right==NULL);
    assert(test_root->right->left==NULL);

    //free up space
    free(test_root->left->left);
    free(test_root->left->right);
    free(test_root->right->right);
    free(test_root->right->left);
    free(test_root->left);
    free(test_root->right);
    free(test_root);

    return;
}

void Test_node_creation(){
    Node* test_node = create_node(1000);

    assert(test_node!=NULL);
    assert(test_node->key==1000);
    assert(test_node->left==NULL);
    assert(test_node->right==NULL);
    free(test_node);
    return;
}

void Test_search(){

    //CREATING TREE WITH NODES
    Node* test_root = create_node(10);
    assert(test_root!=NULL);
    assert(test_root->key==10);
    assert(test_root->left==NULL);
    assert(test_root->right==NULL);

    //LEFT
    test_root = insert(test_root, 8);
    assert(test_root->left->key == 8);
    assert(test_root->right==NULL);

    //LEFT
    test_root = insert(test_root, 6);
    assert(test_root->left->left->key == 6);
    assert(test_root->right==NULL);

    //RIGHT
    test_root = insert(test_root, 18);
    assert(test_root->right->key == 18);
    assert(test_root->left->right==NULL);

    //SEARCH AND CHECK
    Node* find = search(test_root, 6);
    assert(find->key == 6);

    find = search(test_root, 18);
    assert(find->key == 18);

    find = search(test_root, 8);
    assert(find->key == 8);

    find = search(test_root, 10);
    assert(find->key == 10);

    //FREE NODES

    free(test_root->right);
    free(test_root->left->left);
    free(test_root->left);
    free(test_root);

    return;
}

void Test_minimum(){
    //create temporary tree root
    Node* test_root = NULL;
    
    //create tree root
    test_root = create_node(10);
    assert(test_root!=NULL);
    assert(test_root->key==10);
    assert(test_root->left==NULL);
    assert(test_root->right==NULL);

    //insert smaller number
    //LEFT
    test_root = insert(test_root, 7);
    assert(test_root->left->key == 7);
    assert(test_root->right==NULL);

    //insert bigger number
    //RIGHT
    test_root = insert(test_root, 17);
    assert(test_root->right->key == 17);
    assert(test_root->left->right==NULL);

    //check if minimum is 7
    assert(min(test_root)->key==7);

    //insert another smaller number
    test_root = insert(test_root, 5);
    assert(test_root->left->left->key == 5);
    assert(test_root->right->left==NULL);
    assert(test_root->left->right==NULL);

    //minimum should be 4
    assert(min(test_root)->key==5);

    //FREE NODES
    free(test_root->right);
    free(test_root->left->left);
    free(test_root->left);
    free(test_root);
return;
}

void Test_maximum(){
    //create temporary tree root
    Node* test_root = NULL;
    
    //create tree root
    test_root = create_node(10);
    assert(test_root!=NULL);
    assert(test_root->key==10);
    assert(test_root->left==NULL);
    assert(test_root->right==NULL);

    //insert smaller number
    //LEFT
    test_root = insert(test_root, 7);
    assert(test_root->left->key == 7);
    assert(test_root->right==NULL);

    //insert bigger number
    //RIGHT
    test_root = insert(test_root, 17);
    assert(test_root->right->key == 17);
    assert(test_root->left->right==NULL);

    //check if maximum is 17
    assert(max(test_root)->key==17);

    //insert another bigger number
    test_root = insert(test_root, 20);
    assert(test_root->right->right->key == 20);
    assert(test_root->left->right==NULL);
    assert(test_root->right->left==NULL);

    //should be maximum is 20
    assert(max(test_root)->key==20);

//FREE NODES
    free(test_root->left);
    free(test_root->right->right);
    free(test_root->right);
    free(test_root);
    return;
}

void Test_successor(){

    Node* test_root = create_node(8);
    insert(test_root, 5);
    insert(test_root, 12);
    insert(test_root, 11);
    insert(test_root, 15);
    insert(test_root, 7);
    insert(test_root, 2);

    /*      8      our tree
          /   \
         5    12
        / \   / \
       2  7  11  15 
    */


    assert(successor(test_root, 5)->key == 7);
    assert(successor(test_root, 12)->key == 15);
    assert(successor(test_root, 8)->key == 11);

    assert(successor(test_root, 15) == NULL);

    free_tree(test_root);

}

void Test_predecessor(){

    Node* test_root = create_node(8);
    insert(test_root, 5);
    insert(test_root, 12);
    insert(test_root, 11);
    insert(test_root, 15);
    insert(test_root, 7);
    insert(test_root, 2);

    /*      8      our tree
          /   \
         5    12
        / \   / \
       2  7  11  15 
    */

    
    //assert(predecessor(test_root, 5)->key == 2);
    //assert(predecessor(test_root, 12)->key == 11);
    //assert(predecessor(test_root, 8)->key == 7);

    //assert(predecessor(test_root, 2) == NULL);

    free_tree(test_root);

}


void Testing(){
    Test_insert();
    Test_search();
    Test_delete();
    Test_maximum();
    Test_minimum();
    Test_successor();
    //Test_predecessor();
    printf("All tests succesfull\n");
}

