#include "list.h"

int main(void)
{
    list *p = create_head_pointer();
    create_list(p);
    print_list(p);
    return 0;
}
