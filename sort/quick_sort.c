#include "array/random_array.h"
#include <stdio.h>
#include <malloc.h>

void quick(int *, int, int);
int partition(int *, int, int);

int main(void)
{
    int *arr = rand_array();
    print_array(arr);
    quick(arr, 0, ARRNUM - 1);
    print_array(arr);
    free(arr);
    return 0;
}

void quick(int *arr, int lo, int hi)
{
    if (hi <= lo)
        return;

    int j = partition(arr, lo,  hi);
    quick(arr, lo, j - 1);
    quick(arr, j + 1, hi);
}

int partition(int *arr, int lo, int hi)
{
    int i = lo, j = hi + 1;
    int v = arr[lo];
    while (1)
    {
        while (arr[++i] < v)
            if (i == hi)
                break;

        while (v < arr[--j])
            if (j == lo)
                break;

        if (i >= j)
            break;

        exch(arr + i, arr + j);
    }
    exch(arr + lo, arr + j);
    return j;
}
