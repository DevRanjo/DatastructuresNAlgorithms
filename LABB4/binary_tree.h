#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Defining a node in the binary tree
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Declaring the functions
Node* create_node(int key);
Node* insert(Node* root, int key);
Node* search(Node* root, int key);
Node* delete_node(Node* root, int key);
Node* min(Node* root);
Node* max(Node* root);
Node* successor(Node* root, int key);
int tree_size(Node* root);
int tree_depth(Node* root);
void inorder_tree_walk(Node* root);
void free_tree(Node* root);
void display_tree(Node* root);

//testing functions
void Testing();
void Test_search();
void Test_delete();
void Test_maximum();
void Test_minimum();
void Test_successor();
void Test_insert();

#endif
