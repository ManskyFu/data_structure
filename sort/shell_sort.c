#include "array/random_array.h"
#include <malloc.h>
#include <stdlib.h>

void shell(int*);

int main(void)
{
    int *arr = rand_array();
    print_array(arr);
    shell(arr);
    print_array(arr);
    free(arr);
    return 0;
}
void shell(int* arr)
{
    int h = 1;

    while (h < ARRNUM / 3)
        h = h * 3 + 1;
    
    while (h >= 1)
    {
        for (int i = h; i < ARRNUM; ++i)
        {
            for (int j = i; j >= h && arr[j] < arr[j-h]; j -= h)
                exch(arr + j, arr + j - h);
        }
        h /= 3;
    }
}
