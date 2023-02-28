#include "push_swap.h"

void	process_model(char *str, int *stack_a, int *stack_b)
{
	if (str == "sa\n")
		swap_bonus(stack_a, stack_b, 'a');
	else if (str == "sb\n")
		swap_bonus(stack_a, stack_b, 'b');
	else if (str == "ss\n")
		swap_bonus(stack_a, stack_b, 's');
	else if (str == "pa\n")
		push_a_bonus(stack_a, stack_b);
	else if (str == "pb\n")
		push_b_bonus(stack_a, stack_b);
	else if (str == "ra\n")
		rotate_bonus(stack_a, stack_b, 'a');
	else if (str == "rb\n")
		rotate_bonus(stack_a, stack_b, 'b');
	else if (str == "rr\n")
		rotate_bonus(stack_a, stack_b, 'r');
	else if (str == "rra\n")
		reverse_rotate_bonus(stack_a, stack_b, 'a');
	else if (str == "rrb\n")
		reverse_rotate_bonus(stack_a, stack_b, 'b');
	else if (str == "rrr\n")
		reverse_rotate_bonus(stack_a, stack_b, 'r');
	else
		exit(1); // instruction doesn't exist error message on stderror
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	*line;

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
		line = get_next_line(1);
	}
	free(line);
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
