#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int *stack_a;
    int *stack_b;
    int *stack_c;

    stack_a = argument_get(argc, argv);
    stack_b = ft_calloc(stack_a[0], sizeof(int));
    stack_c = ft_calloc(stack_a[0], sizeof(int));
    stack_b[0] = 0;
    stack_c[0] = 0;
    stack_a = indexing(stack_a);
    stack_b = indexing(stack_b);
    if (stack_a[0] == 3)
        sort_three(stack_a, stack_b);
    else if (stack_a[0] == 4)
        sort_four(stack_a, stack_b);
    else if (stack_a[0] == 5)
        sort_five(stack_a, stack_b);
    else
    {
        seperating_into_stacks(stack_a, stack_b);
        send_all_b(stack_a, stack_b);
        sort_five(stack_a, stack_b);
        send_all_a(stack_a, stack_b, stack_c);
        last_sort(stack_a, stack_b);
    }
}