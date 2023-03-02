/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:01:34 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 15:28:59 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_bonus(int *a, int *b, char x)
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
}

void	push_a_bonus(int *a, int *b)
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
	}
}

void	push_b_bonus(int *a, int *b)
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
	}
}

void	rotate_bonus(int *a, int *b, char x)
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
}

void	reverse_rotate_bonus(int *a, int *b, char x)
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
}
