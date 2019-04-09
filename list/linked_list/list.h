#ifndef _LIST_H
#define _LIST_H

typedef struct linked_list {
    char ch;
    struct linked_list *next;
} list;

list *create_head_pointer(void);
void create_list(list *);
void print_list(list *);

#endif
