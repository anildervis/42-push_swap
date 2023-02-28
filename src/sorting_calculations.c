#include "push_swap.h"

// en kısa hamle sayısını her pushtan sonra tekrar bulmak yerine
// daha optimal bir çözüm olarak her elemente + (rotate sayısı % stack[0])
// benzeri bir eklenti yapılabilir
int	road_to_smallest_bigger_index(int *stack_a, int *stack_b, int position)
{
	int	i;
	int	index;

	i = 0;
	index = ft_max_index(stack_a);
	while (++i <= stack_a[0])
		if (((stack_a[i] - stack_b[position]) <= (stack_a[index] - stack_b[position])) && ((stack_a[i] - stack_b[position]) >= 0))
			index = i;
	if (index > ((int)(stack_a[0] / 2)) && position > ((int)(stack_b[0] / 2)))
		return (fmax(stack_a[0] - index + 1, stack_b[0] - position + 1));
	if (index <= ((int)(stack_a[0] / 2)) && position <= ((int)(stack_b[0] / 2)))
		return (fmax(index - 1, position - 1));
	return(fmin(fmin(index - 1 + stack_b[0] - position + 1, position - 1 + stack_a[0] - index + 1), fmin(fmax(index - 1, position - 1), fmax(stack_a[0] - index + 1, stack_b[0] - position + 1))));
}

void	double_rotate(int a_road, int b_road, int *stack_a, int *stack_b)
{
    int	i;

	i = 0;
	while (++i < a_road && i < b_road)
		rotate(stack_a, stack_b, 'r');
	i--;
	while (++i < a_road)
		rotate(stack_a, stack_b, 'a');
	i--;
	while (++i < b_road)
		rotate(stack_a, stack_b, 'b');
}

void	double_reverse_rotate(int a_road, int b_road, int *stack_a, int *stack_b)
{
	int	i;

	i = 0;
	a_road = stack_a[0] - a_road + 1;
	b_road = stack_b[0] - b_road + 1;
	while (++i <= a_road && i <= b_road)
		reverse_rotate(stack_a, stack_b, 'r');
	i--;
	while (++i <= a_road)
		reverse_rotate(stack_a, stack_b, 'a');
	i--;
	while (++i <= b_road)
		reverse_rotate(stack_a, stack_b, 'b');
}

void	on_my_way(int a_road, int b_road, int *stack_a, int *stack_b)
{
	if (a_road <= ((int)(stack_a[0] / 2)))
	{
		b_road = stack_b[0] - b_road + 2;
		while (--a_road)
			rotate(stack_a, stack_b, 'a');
		while (--b_road)
			reverse_rotate(stack_a, stack_b, 'b');
	}
	else
	{
		a_road = stack_a[0] - a_road + 2;
		while (--b_road)
			rotate(stack_a, stack_b, 'b');
		while (--a_road)
			reverse_rotate(stack_a, stack_b, 'a');
	}
}

void	send_all_a(int *stack_a, int *stack_b, int *stack_c)
{
	int	i;
	int	count;
	int	a_road;
	int	b_road;

	while (stack_b[0] > 0)
	{
		count = stack_b[0] + 1;
		stack_c[0] = stack_b[0];
		while (--count > 0)
			stack_c[count] = road_to_smallest_bigger_index(stack_a, stack_b, count);
		b_road = ft_min_index(stack_c);
		a_road = ft_max_index(stack_a);
		i = 0;
		while (++i <= stack_a[0])
			if (((stack_a[i] - stack_b[b_road]) <= (stack_a[a_road] - stack_b[b_road])) && ((stack_a[i] - stack_b[b_road]) >= 0))
				a_road = i;
		if (stack_c[b_road] == fmax(stack_a[0] - a_road + 1, stack_b[0] - b_road + 1))
			double_reverse_rotate(a_road, b_road, stack_a, stack_b);
		else if (stack_c[b_road] == fmax(a_road - 1, b_road - 1))
			double_rotate(a_road, b_road, stack_a, stack_b);
		else
			on_my_way(a_road, b_road, stack_a, stack_b);
		push_a(stack_a, stack_b);
		stack_c[stack_c[0]] = '\0';
	}
}
