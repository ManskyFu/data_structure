#include "random_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *rand_array(void)
{
    int *arr = (int*)malloc(sizeof(int) * ARRNUM);
    srand((unsigned int)time(NULL));

    for (int m = 0; m < ARRNUM; ++m)
        arr[m] = rand() % 999 + 1;
    
    return arr;
}

void print_array(int *arr)
{
    for (int m = 0; m < ARRNUM; m++)
    {
        printf("%3d ", arr[m]);
        if ((m+1) % LINENUM == 0)
            putchar('\n');
    }
    putchar('\n');
}
void exch(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
