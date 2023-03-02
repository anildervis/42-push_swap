/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:02:14 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 12:12:13 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	seperating_into_stacks(int *stack_a, int *stack_b)
{
	int	i;
	int	mid_point;
	int	count;

	i = 0;
	mid_point = (int)(stack_a[0] / 2);
	count = stack_a[0];
	while (++i <= count)
	{
		if (stack_a[1] < mid_point)
			push_b(stack_a, stack_b);
		else
			rotate(stack_a, stack_b, 'a');
	}
}

void	send_all_b(int *stack_a, int *stack_b)
{
	int	i;
	int	count;

	i = 0;
	count = stack_a[0];
	while (++i <= count)
	{
		if (stack_a[1] != (stack_a[0] + stack_b[0] - 1)
			&& stack_a[1] != (stack_a[0] + stack_b[0] - 2)
			&& stack_a[1] != (stack_a[0] + stack_b[0] - 3)
			&& stack_a[1] != (stack_a[0] + stack_b[0] - 4)
			&& stack_a[1] != (stack_a[0] + stack_b[0] - 5))
			push_b(stack_a, stack_b);
		else
			rotate(stack_a, stack_b, 'a');
	}
}

void	sort_three(int *stack_a, int *stack_b)
{
	int	i;
	int	index_of_max;

	i = 0;
	index_of_max = ft_max_index(stack_a);
	if (index_of_max == 1)
		rotate(stack_a, stack_b, 'a');
	else if (index_of_max == 2)
		reverse_rotate(stack_a, stack_b, 'a');
	if (stack_a[1] > stack_a[2])
		swap(stack_a, stack_b, 'a');
}

void	sort_four(int *stack_a, int *stack_b)
{
	int	index_of_max;

	index_of_max = ft_max_index(stack_a);
	if (index_of_max == 2 || index_of_max == 3)
		rotate(stack_a, stack_b, 'a');
	if (index_of_max == 3)
		rotate(stack_a, stack_b, 'a');
	else if (index_of_max == 4)
		reverse_rotate(stack_a, stack_b, 'a');
	push_b(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	push_a(stack_a, stack_b);
	rotate(stack_a, stack_b, 'a');
}

void	sort_five(int *stack_a, int *stack_b)
{
	int	index_of_max;

	index_of_max = ft_max_index(stack_a);
	if (index_of_max == 2 || index_of_max == 3)
		rotate(stack_a, stack_b, 'a');
	if (index_of_max == 3)
		rotate(stack_a, stack_b, 'a');
	if (index_of_max == 4 || index_of_max == 5)
		reverse_rotate(stack_a, stack_b, 'a');
	if (index_of_max == 4)
		reverse_rotate(stack_a, stack_b, 'a');
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
	rotate(stack_a, stack_b, 'a');
}
