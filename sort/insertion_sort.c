#include "array/random_array.h"
#include <stdio.h>
#include <malloc.h>

void insertion(int *);

int main(void)
{
    int *arr = rand_array();
    print_array(arr);
    insertion(arr);
    print_array(arr);
    free(arr);
    return 0;
}
void insertion(int *arr)
{
    for (int i = 1; i < ARRNUM; i++)
    {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--)
            exch(arr + j, arr + j - 1);
    }
}
