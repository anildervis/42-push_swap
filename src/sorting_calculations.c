/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:02:11 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 20:11:39 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	road_to_smallest_bigger_index(int *s_a, int *s_b, int b_pos)
{
	int	i;
	int	a_pos;

	i = 0;
	a_pos = ft_max_index(s_a);
	while (++i <= s_a[0])
		if (((s_a[i] - s_b[b_pos]) <= (s_a[a_pos] - s_b[b_pos]))
			&& ((s_a[i] - s_b[b_pos]) >= 0))
			a_pos = i;
	if (a_pos > ((int)(s_a[0] / 2)) && b_pos > ((int)(s_b[0] / 2)))
		return (ft_max(s_a[0] - a_pos + 1, s_b[0] - b_pos + 1));
	if (a_pos <= ((int)(s_a[0] / 2)) && b_pos <= ((int)(s_b[0] / 2)))
		return (ft_max(a_pos - 1, b_pos - 1));
	return (ft_min(ft_min(a_pos - 1 + s_b[0] - b_pos + 1,
				b_pos - 1 + s_a[0] - a_pos + 1),
			ft_min(ft_max(a_pos - 1, b_pos - 1),
				ft_max(s_a[0] - a_pos + 1, s_b[0] - b_pos + 1))));
}

void	double_rotate(int a_road, int b_road, int *s_a, int *s_b)
{
	int	i;

	i = 0;
	while (++i < a_road && i < b_road)
		rotate(s_a, s_b, 'r');
	i--;
	while (++i < a_road)
		rotate(s_a, s_b, 'a');
	i--;
	while (++i < b_road)
		rotate(s_a, s_b, 'b');
}

void	double_reverse_rotate(int a_road, int b_road, int *s_a, int *s_b)
{
	int	i;

	i = 0;
	a_road = s_a[0] - a_road + 1;
	b_road = s_b[0] - b_road + 1;
	while (++i <= a_road && i <= b_road)
		reverse_rotate(s_a, s_b, 'r');
	i--;
	while (++i <= a_road)
		reverse_rotate(s_a, s_b, 'a');
	i--;
	while (++i <= b_road)
		reverse_rotate(s_a, s_b, 'b');
}

void	on_my_way(int a_road, int b_road, int *s_a, int *s_b)
{
	if (a_road <= ((int)(s_a[0] / 2)))
	{
		b_road = s_b[0] - b_road + 2;
		while (--a_road)
			rotate(s_a, s_b, 'a');
		while (--b_road)
			reverse_rotate(s_a, s_b, 'b');
	}
	else
	{
		a_road = s_a[0] - a_road + 2;
		while (--b_road)
			rotate(s_a, s_b, 'b');
		while (--a_road)
			reverse_rotate(s_a, s_b, 'a');
	}
}

void	send_all_a(int *s_a, int *s_b, int *s_c)
{
	int	i;
	int	a_road;
	int	b_road;

	while (s_b[0] > 0)
	{
		i = s_b[0] + 1;
		s_c[0] = s_b[0];
		while (--i > 0)
			s_c[i] = road_to_smallest_bigger_index(s_a, s_b, i);
		b_road = ft_min_index(s_c);
		a_road = ft_max_index(s_a);
		while (++i <= s_a[0])
			if (((s_a[i] - s_b[b_road]) <= (s_a[a_road] - s_b[b_road]))
				&& ((s_a[i] - s_b[b_road]) >= 0))
				a_road = i;
		if (s_c[b_road] == ft_max(s_a[0] - a_road + 1, s_b[0] - b_road + 1))
			double_reverse_rotate(a_road, b_road, s_a, s_b);
		else if (s_c[b_road] == ft_max(a_road - 1, b_road - 1))
			double_rotate(a_road, b_road, s_a, s_b);
		else
			on_my_way(a_road, b_road, s_a, s_b);
		push_a(s_a, s_b);
		s_c[s_c[0]] = '\0';
	}
}
