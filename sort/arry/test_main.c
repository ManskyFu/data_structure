#include "random_array.h"
#include <stdio.h>

int main(void)
{
    int **arr = rand_array();
    print_array(arr);
    free_array(arr);
    return 0;
}
