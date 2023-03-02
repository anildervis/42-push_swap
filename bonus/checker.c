/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:01:24 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 15:28:25 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_equal(char *str, char *to_check)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] != to_check[i])
			return (0);
	return (1);
}

void	process_model(char *str, int *stack_a, int *stack_b)
{
	if (is_equal(str, "sa\n"))
		swap_bonus(stack_a, stack_b, 'a');
	else if (is_equal(str, "sb\n"))
		swap_bonus(stack_a, stack_b, 'b');
	else if (is_equal(str, "ss\n"))
		swap_bonus(stack_a, stack_b, 's');
	else if (is_equal(str, "pa\n"))
		push_a_bonus(stack_a, stack_b);
	else if (is_equal(str, "pb\n"))
		push_b_bonus(stack_a, stack_b);
	else if (is_equal(str, "ra\n"))
		rotate_bonus(stack_a, stack_b, 'a');
	else if (is_equal(str, "rb\n"))
		rotate_bonus(stack_a, stack_b, 'b');
	else if (is_equal(str, "rr\n"))
		rotate_bonus(stack_a, stack_b, 'r');
	else if (is_equal(str, "rra\n"))
		reverse_rotate_bonus(stack_a, stack_b, 'a');
	else if (is_equal(str, "rrb\n"))
		reverse_rotate_bonus(stack_a, stack_b, 'b');
	else if (is_equal(str, "rrr\n"))
		reverse_rotate_bonus(stack_a, stack_b, 'r');
	else
		error();
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
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
	line = get_next_line(0);
	while (line != NULL)
	{
		process_model(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && stack_b[0] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
