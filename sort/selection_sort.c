#include <stdlib.h>
#include <stdio.h>
#include "array/random_array.h"

void selection(int *);

int main(void)
{
    int *arr = rand_array();
    print_array(arr);
    selection(arr);
    print_array(arr);
    free(arr);
    return 0;
}

void selection(int *arr)
{
   for (int i = 0; i < ARRNUM; i++)
   {
       int min = i;
       for (int j = i + 1; j < ARRNUM; ++j)
           if (arr[min] > arr[j])
               min = j;

       exch(arr + min, arr + i);
   }
}
