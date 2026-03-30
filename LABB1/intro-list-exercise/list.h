// Interface for a simple list of integers

#ifndef LIST_H
#define LIST_H

typedef struct List List;

extern List *create_list(void);
extern void destroy_list(List *victim);
extern List *copy_list(List *original);
extern int list_length(List *this_list);
extern int find_position_in_list(List *this_list, int wanted);
extern void prepend_to_list(List *this_list, int data);
extern void append_to_list(List *this_list, int data);
extern void print_list(List *this_list);

#endif
