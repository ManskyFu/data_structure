#include "init_arr.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void init_arr(int *arr, int len)
{
    srand((unsigned int)time(NULL));
    for (int m = 0; m < len; ++m)
        arr[m] = rand() % 999 + 1;
}
void print_arr(int *arr, int len)
{
    for (int m = 0; m < len; ++m)
    {
        printf("%3d ", arr[m]);
        if ((m + 1) % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
}
void exch(int *a, int *b)
{
    int tmp = *a;
    *a      = *b;
    *b      = tmp;
}
