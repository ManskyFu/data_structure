#ifndef _STACK_H_
#define _STACK_H_

typedef struct Stack {
    int data;
    struct Stack *next;
} stack;

stack *create_stack(void);
void push(stack *, int);
void pop(stack *);
void print_stack(stack *);
void delete_stack(stack *);
#endif
