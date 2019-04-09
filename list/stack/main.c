#include "stack.h"
#include <stdio.h>

int main(void)
{
    int data = 0;

    stack *s = create_stack();

    puts("Please enter the data: ('q' to quit)");
    while (data != -1)
    {
        scanf("%d", &data);
        push(s, data);
    }
    puts("Plese enter how many numbers you want to pop:");
    scanf("%d", &data);
    for (int m = 0; m < data; m++)
        pop(s);
    print_stack(s);
    delete_stack(s);
    return 0;
}
