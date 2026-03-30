// A completely different implementation of the simple list of integers

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

struct List {
    int *data;
    int used_length;
    int allocated_length;
};

List *create_list(void) {
    List *new_list = malloc(sizeof(List));
    new_list->data = NULL;
    new_list->used_length = 0;
    new_list->allocated_length = 0;
    return new_list;
}

void destroy_list(List *victim) {
    assert(victim != NULL);
    free(victim->data);
    free(victim);
}

List *copy_list(List *original) {
    assert(original != NULL);
    List *copy = create_list();
    for (int i = 0; i < original->used_length; ++i)
        append_to_list(copy, original->data[i]);
    return copy;
}

int list_length(List *this_list) {
    assert(this_list != NULL);
    return this_list->used_length;
}

int find_position_in_list(List *this_list, int wanted) {
    assert(this_list != NULL);
    for (int i = 0; i < this_list->used_length; ++i) {
        if (this_list->data[i] == wanted)
            return i;
    }
    return -1;
}

static void expand(List *this_list) {
    if (this_list->used_length + 1 > this_list->allocated_length){
        if (this_list->allocated_length == 0)
            this_list->allocated_length = 8;
        else
            this_list->allocated_length *= 2;
        this_list->data = realloc(this_list->data, sizeof(int) * this_list->allocated_length);
    }
}

// For long lists, this will be slow. Exercise: Why?
void prepend_to_list(List *this_list, int data) {
    assert(this_list != NULL);
    expand(this_list);
    for (int i = this_list->used_length - 1; i >= 0; --i)
        this_list->data[i + 1] = this_list->data[i];
    this_list->data[0] = data;
    this_list->used_length += 1;
}

void append_to_list(List *this_list, int data) {
    assert(this_list != NULL);
    expand(this_list);
    this_list->data[this_list->used_length] = data;
    this_list->used_length += 1;
}

void print_list(List *this_list) {
    assert(this_list != NULL);
    printf("[");
    for (int i = 0; i < this_list->used_length; ++i)
        printf(" %d", this_list->data[i]);
    printf(" ]\n");
}

