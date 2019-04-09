#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *create_head_pointer(void)
{
    list *phead = (list*)malloc(sizeof(list));
    phead->next = NULL;
    return phead;
}
void create_list(list *phead)
{
    list *prev = phead, *rear;
    
    for (int c = 'A'; c <= 'Z'; c++)
    {
        rear = (list*)malloc(sizeof(list));
        rear->next = NULL;
        rear->ch   = c;
        prev->next = rear;
        prev       = rear;
    }
}
void print_list(list *phead)
{
    list *tmp = phead->next;

    while (tmp)
    {
        printf("%c ", tmp->ch);
        tmp = tmp->next;
    }
    putchar('\n');
}
