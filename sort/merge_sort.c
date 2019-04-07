#include "array/random_array.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

void merge(int *, int, int, int, int *);
void merge_sort(int *,int,int,int *);

int main(void)
{
    int *arr = rand_array();
    int tmp[ARRNUM];
    print_array(arr);
    merge_sort(arr, 0, ARRNUM - 1, tmp);
    print_array(arr);
    free(arr);
    return 0;
}
void merge(int arr[], int left, int mid, int right, int *temp){
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid&&j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else     
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];

    memcpy(arr + left, temp + left, sizeof(int)*(right - left+1));
}
void merge_sort(int arr[],int left,int right,int *temp){
    int mid = 0;
    if (left < right)
    {
        mid = left + (right - left) / 2;
        merge_sort(arr, left, mid, temp);
        merge_sort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }

}
