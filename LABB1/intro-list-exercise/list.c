// Implementation of the simple list of integers

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

typedef struct ListLink ListLink;

struct ListLink {
    int data;
    ListLink *next;
};

struct List {
    ListLink *first;
};

static ListLink *create_link(void) {
    ListLink *new_link = malloc(sizeof(ListLink));
    return new_link;
}

List *create_list(void) {
    List *new_list = malloc(sizeof(List));
    new_list->first = NULL;
    return new_list;
}

void destroy_list(List *victim) {
    assert(victim != NULL);
    ListLink *current = victim->first;
    while (current != NULL) {
        ListLink *doomed = current;
        current = current->next;
        free(doomed);
    }
    free(victim);
}

// For long lists, this will be very slow. Exercise: Why?
List *copy_list(List *original) {
    assert(original != NULL);
    List *copy = create_list();
    ListLink *current = original->first;
    while (current != NULL) {
        append_to_list(copy, current->data);
        current = current->next;
    }
    return copy;
}

int list_length(List *this_list) {
    assert(this_list != NULL);
    ListLink *current = this_list->first;
    int length = 0;
    while (current != NULL) {
        ++length;
        current = current->next;
    }
    return length;
}

int find_position_in_list(List *this_list, int wanted) {
    assert(this_list != NULL);
    ListLink *current = this_list->first;
    int position = 0;
    while (current != NULL) {
        if (current->data == wanted)
            return position;
        ++position;
        current = current->next;
    }
    return -1;
}

void prepend_to_list(List *this_list, int data) {
    assert(this_list != NULL);
    ListLink *new_link = create_link();
    new_link->data = data;
    new_link->next = this_list->first;
    this_list->first = new_link;
}

void append_to_list(List *this_list, int data) {
    assert(this_list != NULL);
    ListLink *new_link = create_link();
    new_link->data = data;
    new_link->next = NULL;
    if (this_list->first == NULL) {
        this_list->first = new_link;
    }
    else {
        ListLink *current = this_list->first;
        ListLink *trailing_link = NULL;
        while (current != NULL) {
            trailing_link = current;
            current = current->next;
        }
        trailing_link->next = new_link;
    }
}

void print_list(List *this_list) {
    assert(this_list != NULL);
    ListLink *current = this_list->first;
    printf("[");
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    printf(" ]\n");
}
