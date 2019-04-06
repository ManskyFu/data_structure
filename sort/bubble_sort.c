#include "array/random_array.h"
#include <malloc.h>
#include <stdio.h>

void bubble(int *);

int main(void)
{
    int *arr = rand_array();
    print_array(arr);
    bubble(arr);
    print_array(arr);
    free(arr);
    return 0;
}
void bubble(int *arr)
{
    for (int m = 0; m < ARRNUM - 1; m++)
        for (int n = 0; n < ARRNUM - 1 - m; n++)
            if (arr[n] > arr[n + 1])
                exch(arr + n, arr + n + 1);
}
