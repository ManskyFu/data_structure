#include "array/init_arr.h"
#include <stdio.h>

int sequential_search(int *, int);

int main(void)
{
    int arr[100];
    int subscript;
    init_arr(arr, 100);
    print_arr(arr, 100);
    subscript = sequential_search(arr, 100);
    print_subscript(subscript);
    return 0;
}
int sequential_search(int *arr, int len)
{
    int num;
    puts("Enter the number you want to search:");
    scanf("%d", &num);

    for (int m = 0; m < len; ++m)
    {
        if (num == arr[m])
            return m;
    }
    return NONNUM;
}
