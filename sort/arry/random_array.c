#include "random_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **rand_array(void)
{
    int **arr = (int**)malloc(sizeof(int*) * LINENUM);
    for (int m = 0; m < LINENUM; m++)
    {
        arr[m] = (int *)malloc(sizeof(int) * LINENUM);
    }

    srand((unsigned int)time(NULL));
    for (int m = 0; m < LINENUM; m++)
        for (int n = 0; n < LINENUM; n++)
            arr[m][n] = rand() % 999 + 1;

    return arr;
}
void free_array(int **arr)
{
    for (int m = 0; m < LINENUM; ++m)
        free(arr[m]);
    free(arr);
}
void print_array(int**arr)
{
    for (int m = 0; m < LINENUM; m++)
    {
        for (int n = 0; n < LINENUM; n++)
            printf("%3d ", arr[m][n]);
        putchar('\n');
    }
    putchar('\n');
}
