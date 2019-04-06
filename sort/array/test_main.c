#include "random_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = rand_array();
    print_array(arr);
    free(arr);
    return 0;
}
