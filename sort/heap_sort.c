#include "array/random_array.h"
#include <stdio.h>
#include <stdlib.h>

void sink(int *, int, int);
void heap_sort(int *, int);

int main(void)
{
    int *arr = rand_array();
    int tmp[ARRNUM + 1];

    for (int m = 0; m < ARRNUM; m++)
        tmp[m+1] = arr[m];
    
    print_array(arr);
    heap_sort(tmp, ARRNUM);

    for (int m = 0; m < ARRNUM; ++m)
        arr[m] = tmp[m+1];

    print_array(arr);
    free(arr);
    return 0;
}
void sink(int *arr, int k, int N)
{
    while (2 * k <= N)
    {
        int j = 2 * k;
        if (j < N && arr[j] < arr[j + 1])
            j++;
        if (arr[k] >= arr[j])
            break;

        exch(arr + k, arr + j);
        k = j;
    }
}
void heap_sort(int *arr, int N)
{
    for (int k = N/2; k>= 1; k--)
        sink(arr, k, N);

    while (N > 1)
    {
        exch(&arr[1], &arr[N--]);
        sink(arr, 1, N);
    }
}
