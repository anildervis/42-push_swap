/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:02:19 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 15:31:42 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b, char x)
{
	int	tmp;

	if ((x == 'a' || x == 's') && !(a[0] < 2))
	{
		tmp = a[2];
		a[2] = a[1];
		a[1] = tmp;
	}
	if ((x == 'b' || x == 's') && !(b[0] < 2))
	{
		tmp = b[2];
		b[2] = b[1];
		b[1] = tmp;
	}
	if (x == 'a')
		write(1, "sa\n", 3);
	else if (x == 'b')
		write(1, "sb\n", 3);
	else if (x == 's')
		write(1, "ss\n", 3);
}

void	push_a(int *a, int *b)
{
	int	i;

	i = -1;
	if (b[0] > 0)
	{
		while ((a[0] - ++i) > 0)
			a[a[0] + 1 - i] = a[a[0] - i];
		a[1] = b[1];
		i = 0;
		while (++i < b[0])
			b[i] = b[1 + i];
		b[i] = '\0';
		a[0]++;
		b[0]--;
		write(1, "pa\n", 3);
	}
}

void	push_b(int *a, int *b)
{
	int	i;

	i = -1;
	if (a[0] > 0)
	{
		while ((b[0] - ++i) > 0)
			b[b[0] + 1 - i] = b[b[0] - i];
		b[1] = a[1];
		i = 0;
		while (++i < a[0])
			a[i] = a[1 + i];
		a[i] = '\0';
		b[0]++;
		a[0]--;
		write(1, "pb\n", 3);
	}
}

void	rotate(int *a, int *b, char x)
{
	int	i;
	int	tmp;

	i = 0;
	if (x == 'a' || x == 'r')
	{
		tmp = a[1];
		while (++i < a[0])
			a[i] = a[i + 1];
		a[a[0]] = tmp;
	}
	i = 0;
	if (x == 'b' || x == 'r')
	{
		tmp = b[1];
		while (++i < b[0])
			b[i] = b[1 + i];
		b[b[0]] = tmp;
	}
	if (x == 'a')
		write(1, "ra\n", 3);
	else if (x == 'b')
		write(1, "rb\n", 3);
	else if (x == 'r')
		write(1, "rr\n", 3);
}

void	reverse_rotate(int *a, int *b, char x)
{
	int	i;
	int	tmp;

	i = a[0] + 1;
	if (x == 'a' || x == 'r')
	{
		tmp = a[a[0]];
		while (--i > 1)
			a[i] = a[i - 1];
		a[1] = tmp;
	}
	i = b[0] + 1;
	if (x == 'b' || x == 'r')
	{
		tmp = b[b[0]];
		while (--i > 1)
			b[i] = b[i - 1];
		b[1] = tmp;
	}
	if (x == 'a')
		write(1, "rra\n", 4);
	else if (x == 'b')
		write(1, "rrb\n", 4);
	else if (x == 'r')
		write(1, "rrr\n", 4);
}
