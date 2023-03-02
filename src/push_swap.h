/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:02:08 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 20:11:28 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../get_git/get_next_line_bonus.h"
# include "../libft/libft.h"

void	error(void);

// ----------stack_functions.c------------
void	swap(int *a, int *b, char x);
void	push_a(int *a, int *b);
void	push_b(int *a, int *b);
void	rotate(int *a, int *b, char x);
void	reverse_rotate(int *a, int *b, char x);

// -----------stack_read.c----------------
int		*argument_get(int argc, char **argv);
int		*stack_converter(char *str);
void	check_duplicates(int *stack);
int		*indexing(int *list);

// -------------sorting.c-----------------
void	seperating_into_stacks(int *stack_a, int *stack_b);
void	send_all_b(int *stack_a, int *stack_b);
void	sort_three(int *stack_a, int *stack_b);
void	sort_four(int *stack_a, int *stack_b);
void	sort_five(int *stack_a, int *stack_b);

// ----------sorting_calculations.c------------
int		road_to_smallest_bigger_index(int *s_a, int *s_b, int b_pos);
void	double_rotate(int a_road, int b_road, int *s_a, int *s_b);
void	double_reverse_rotate(int a_road, int b_road, int *s_a, int *s_b);
void	on_my_way(int a_road, int b_road, int *s_a, int *s_b);
void	send_all_a(int *s_a, int *s_b, int *s_c);

// -----------stack_check.c----------------
void	last_sort(int *stack_a, int *stack_b);
int		is_sorted(int *stack);
int		ft_max_index(int *stack);
int		ft_min_index(int *stack);

#endif