// example-tree-test.c
// As an inspiration, here is some code for testing a binary tree.
// There is no requirement that your implementation of a tree must
// pass these tests. Also, it will probably not work with your code
// without some modification, since I am sure it has other
// names and design choices, but perhaps it can serve as an
// inspiration for your own testing.
//
// Thomas Padron-McCarthy (thomas.padron-mccarthy@oru.se)
// Mon Feb 27 11:55:30 CET 2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "binary-tree.h"

// For testing: Sorts the array "a" of length "length" in random order
static void shuffle_array(int a[], int length) {
    for (int randomized = 0; randomized < length; ++randomized) {
        // Select a random position in the rest of the array
        int selected = randomized + rand() % (length - randomized);
        // Swap the current position with the random position
        int oldvalue = a[randomized];
        a[randomized] = a[selected];
        a[selected] = oldvalue;
    }
}

// For testing: Finds the max in an array segment
static int arraymax(int a[], int first, int last) {
    int maxsofar = a[first];
    for (int i = first; i <= last; ++i) {
        if (a[i] > maxsofar)
            maxsofar = a[i];
    }
    return maxsofar;
}

// For testing: Finds the min in an array segment
static int arraymin(int a[], int first, int last) {
    int minsofar = a[first];
    for (int i = first; i <= last; ++i) {
        if (a[i] < minsofar)
            minsofar = a[i];
    }
    return minsofar;
}

// It is better to build (and delete) many smaller trees
// than one huge one, since with one huge tree
// we would only have a single root node,
// and only test inserting the root node once.

#define STRESS_TEST_SIZE 1000
#define NUM_STRESS_TESTS 100

// Large arrays may be too large for the stack, so put it here
static int testnumbers[STRESS_TEST_SIZE];

void stress_test(void) {
    // Create two trees
    BinaryTree *T1 = bt_create();
    BinaryTree *T2 = bt_create();

    // Check that both trees are empty
    assert(bt_depth(T1) == 0);
    assert(bt_size(T1) == 0);
    assert(bt_search(T1, 17) == NULL);
    assert(bt_search(T1, 18) == NULL);
    assert(bt_minimum(T1) == NULL);
    assert(bt_maximum(T1) == NULL);
    assert(bt_depth(T2) == 0);
    assert(bt_size(T2) == 0);
    assert(bt_search(T2, 17) == NULL);
    assert(bt_search(T2, 18) == NULL);
    assert(bt_minimum(T2) == NULL);
    assert(bt_maximum(T2) == NULL);

    // Insert a node with key 17 in tree T1
    BinaryTreeNode *N17 = bt_create_node(17);
    bt_insert(T1, N17);

    // Check that tree T1 contains the node with key 17
    assert(bt_depth(T1) == 1);
    assert(bt_size(T1) == 1);
    assert(bt_search(T1, 17) == N17);
    assert(bt_search(T1, 18) == NULL);
    assert(bt_get_node_key(N17) == 17);
    assert(bt_minimum(T1) == N17);
    assert(bt_maximum(T1) == N17);
    assert(bt_successor(T1, N17) == NULL);
    assert(bt_predecessor(T1, N17) == NULL);

    // Check that tree T2 is still empty
    assert(bt_depth(T2) == 0);
    assert(bt_size(T2) == 0);
    assert(bt_search(T2, 17) == NULL);
    assert(bt_search(T2, 18) == NULL);
    assert(bt_minimum(T2) == NULL);
    assert(bt_maximum(T2) == NULL);

    // Stress test: Fill T2 with many numbers in random order
    for (int i = 0; i < STRESS_TEST_SIZE; ++i)
        testnumbers[i] = i;
    shuffle_array(testnumbers, STRESS_TEST_SIZE);
    for (int i = 0; i < STRESS_TEST_SIZE; ++i) {
        int thisnumber = testnumbers[i];
        BinaryTreeNode *N = bt_create_node(thisnumber);
        bt_insert(T2, N);
        assert(bt_size(T2) == i + 1);
        assert(bt_search(T2, thisnumber) == N);
        assert(bt_get_node_key(N) == thisnumber);
        if (thisnumber != 17)
            assert(bt_search(T1, thisnumber) == NULL);
        else
            assert(bt_search(T1, thisnumber) == N17);
        int min_inserted = arraymin(testnumbers, 0, i);
        assert(bt_search(T2, min_inserted - 1) == NULL);
        BinaryTreeNode *min_node = bt_search(T2, min_inserted);
        assert(bt_minimum(T2) == min_node);
        assert(bt_get_node_key(min_node) == min_inserted);
        assert(bt_predecessor(T2, min_node) == NULL);
        int max_inserted = arraymax(testnumbers, 0, i);
        assert(bt_search(T2, max_inserted + 1) == NULL);
        BinaryTreeNode *max_node = bt_search(T2, max_inserted);
        assert(bt_maximum(T2) == max_node);
        assert(bt_get_node_key(max_node) == max_inserted);
        assert(bt_successor(T2, max_node) == NULL);
    }

    // Check that tree T1 hasn't changed
    assert(bt_depth(T1) == 1);
    assert(bt_size(T1) == 1);
    assert(bt_search(T1, 17) == N17);
    assert(bt_search(T1, 18) == NULL);
    assert(bt_get_node_key(N17) == 17);
    assert(bt_minimum(T1) == N17);
    assert(bt_maximum(T1) == N17);
    assert(bt_successor(T1, N17) == NULL);
    assert(bt_predecessor(T1, N17) == NULL);

    // Remove the node with key 17 from tree T1
    BinaryTreeNode *doomed = bt_search(T1, 17);
    assert(bt_get_node_key(doomed) == 17);
    bt_delete(T1, doomed);
    bt_destroy_node(N17);

    // Check that T1 is empty again
    assert(bt_depth(T1) == 0);
    assert(bt_size(T1) == 0);
    assert(bt_search(T1, 17) == NULL);
    assert(bt_search(T1, 18) == NULL);
    assert(bt_minimum(T1) == NULL);
    assert(bt_maximum(T1) == NULL);

    // Stress test: Empty T2, in a new random order
    shuffle_array(testnumbers, STRESS_TEST_SIZE);
    for (int i = 0; i < STRESS_TEST_SIZE; ++i) {
        int thisnumber = testnumbers[i];
        BinaryTreeNode *doomed = bt_search(T2, thisnumber);
        assert(bt_get_node_key(doomed) == thisnumber);
        bt_delete(T2, doomed);
        bt_destroy_node(doomed);
        assert(bt_search(T2, thisnumber) == NULL);
        assert(bt_size(T2) == STRESS_TEST_SIZE - i - 1);
        if (i != STRESS_TEST_SIZE - 1) {
            int min_remaining = arraymin(testnumbers, i + 1, STRESS_TEST_SIZE - 1);
            assert(bt_search(T2, min_remaining - 1) == NULL);
            BinaryTreeNode *min_node = bt_search(T2, min_remaining);
            assert(bt_minimum(T2) == min_node);
            assert(bt_predecessor(T2, min_node) == NULL);
            int max_remaining = arraymax(testnumbers, i + 1, STRESS_TEST_SIZE - 1);
            assert(bt_search(T2, max_remaining + 1) == NULL);
            BinaryTreeNode *max_node = bt_search(T2, max_remaining);
            assert(bt_maximum(T2) == max_node);
            assert(bt_get_node_key(max_node) == max_remaining);
            assert(bt_successor(T2, max_node) == NULL);
        }
    }

    // Check that both trees are empty
    assert(bt_depth(T1) == 0);
    assert(bt_size(T1) == 0);
    assert(bt_search(T1, 17) == NULL);
    assert(bt_search(T1, 18) == NULL);
    assert(bt_minimum(T1) == NULL);
    assert(bt_maximum(T1) == NULL);
    bt_destroy(T1);
    assert(bt_depth(T2) == 0);
    assert(bt_size(T2) == 0);
    assert(bt_search(T2, 17) == NULL);
    assert(bt_search(T2, 18) == NULL);
    assert(bt_minimum(T2) == NULL);
    assert(bt_maximum(T2) == NULL);
    bt_destroy(T2);
} // stress_test

int main(void) {
    printf("Running example-tree-test...\n");
    srand(time(NULL));
    
    for (int i = 0; i < NUM_STRESS_TESTS; ++i)
        stress_test();

    printf("example-tree-test: No errors detected.\n");

    return 0;
} // main