/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:01:28 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 15:25:41 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../get_git/get_next_line_bonus.h"
# include "../libft/libft.h"

// --------------checker.c--------------
int		is_equal(char *str, char *to_check);
void	process_model(char *str, int *stack_a, int *stack_b);
void	error(void);

// --------stack_bonus_functions.c--------
void	swap_bonus(int *a, int *b, char x);
void	push_a_bonus(int *a, int *b);
void	push_b_bonus(int *a, int *b);
void	rotate_bonus(int *a, int *b, char x);
void	reverse_rotate_bonus(int *a, int *b, char x);

// --------stack_bonus_functions.c--------
int		*argument_get(int argc, char **argv);
int		*stack_converter(char *str);
void	check_duplicates(int *stack);
int		*indexing(int *list);
int		is_sorted(int *stack);

#endif