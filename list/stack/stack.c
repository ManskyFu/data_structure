#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack *create_stack(void)
{
    stack *bottom = (stack*)malloc(sizeof(stack));
    bottom->next  = NULL;
    bottom->data  = 0;
    stack *top    = (stack*)malloc(sizeof(stack));
    top->data     = 0;
    top->next     = bottom;

    return top;
}
void push(stack *s, int data)
{
    stack *add = (stack*)malloc(sizeof(stack));
    if (add == NULL)
    {
        puts("No more space !");
        return;
    }
    add->data  = data;
    add->next  = s->next;
    s->next    = add;
}
void pop(stack *s)
{
    if (s->next->next == NULL)
    {
        puts("Stack is empty!");
        return;
    }
    stack *tmp = s->next;
    s->next    = tmp->next;
    free(tmp);
}
void print_stack(stack *s)
{
    stack *p = s->next;

    while (p->next)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void delete_stack(stack *s)
{
    stack *tmp, *p = s;
    while (p)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}
