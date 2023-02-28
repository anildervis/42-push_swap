#include "push_swap.h"

void	last_sort(int *stack_a, int *stack_b)
{
	int	i;
	int	index_of_max;

	i = 0;
	index_of_max = ft_max_index(stack_a);
	if (index_of_max > ((int)(stack_a[0] / 2)))
	{
		while (++index_of_max <= stack_a[0])
			reverse_rotate(stack_a, stack_b, 'a');
	}
	else
	{
		while (--index_of_max >= 0)
			rotate(stack_a, stack_b, 'a');
	}
}

int	is_sorted(int *stack)
{
	int	i;

	i = 0;
	while (++i < stack[0])
		if (stack[i] > stack[i + 1])
			return (0);
	return (1);
}

int	ft_max_index(int *stack)
{
	int	i;
	int	rt;

	i = 0;
	rt = 1;
	while (++i <= stack[0])
		if (stack[rt] < stack[i])
			rt = i;
	return (rt);
}

int	ft_min_index(int *stack)
{
	int	i;
	int	rt;

	i = 0;
	rt = 1;
	while (++i <= stack[0])
		if (stack[rt] > stack[i])
			rt = i;
	return (rt);
}
