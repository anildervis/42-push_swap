#include "push_swap.h"

void process_model(char *str, int *stack_a, int *stack_b)
{
    if (str == "sa\n")
        swap(stack_a, stack_b, 'a');
    else if (str == "sb\n")
        swap(stack_a, stack_b, 'b');
    else if (str == "ss\n")
        swap(stack_a, stack_b, 's');
    else if (str == "pa\n")
        push_a(stack_a, stack_b);
    else if (str == "pb\n")
        push_b(stack_a, stack_b);
    else if (str == "ra\n")
        rotate(stack_a, stack_b, 'a');
    else if (str == "rb\n")
        rotate(stack_a, stack_b, 'b');
    else if (str == "rr\n")
        rotate(stack_a, stack_b, 'r');
    else if (str == "rra\n")
        reverse_rotate(stack_a, stack_b, 'a');
    else if (str == "rrb\n")
        reverse_rotate(stack_a, stack_b, 'b');
    else if (str == "rrr\n")
        reverse_rotate(stack_a, stack_b, 'r');
    // for errors -> change func type
    // else
    //     return (0);
    // return (1);
}

int main(int argc, char **argv)
{
    int fd;
    int *stack_a;
    int *stack_b;
    char *line;

    stack_a = argument_get(argc, argv);
    stack_b = ft_calloc(stack_a[0], sizeof(int));
    stack_b[0] = 0;
    stack_a = indexing(stack_a);
    stack_b = indexing(stack_b);
    line = get_next_line(1);
    while (line)
    {
        process_model(line, stack_a, stack_b);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    if (is_sorted(stack_a))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    return (0);
}