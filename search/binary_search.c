#include "array/init_arr.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int *, int);
void sort(int *, int);

int main(void)
{
    int subscript, arr[100];
    init_arr(arr, 100);
    print_arr(arr, 100);
    sort(arr, 100);
    print_arr(arr, 100);
    subscript = binary_search(arr, 100);
    print_subscript(subscript);
    return 0;
}
int binary_search(int *arr, int len)
{
    int lo = 0, hi = len - 1;
    int num;

    puts("Enter the number you want to search:");
    scanf("%d", &num);

    while (1)
    {
        int mid = lo + (hi - lo) / 2;
        
        if (num < arr[0] || num > arr[len - 1])
            return NONNUM;
        else if (num != arr[mid] && lo == hi)
            return NONNUM;
        else if (num < arr[mid])
            hi = mid - 1;
        else if (num > arr[mid])
            lo = mid + 1;
        else
            return mid;
    }
}
void sort(int *arr, int len)
{
    for (int m = 0; m < len - 1; m++)
        for (int n = 0; n < len - m - 1; n++)
            if (arr[n] > arr[n + 1])
                exch(arr + n, arr + n + 1);
}
