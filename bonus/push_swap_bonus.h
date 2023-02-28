#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include <stdio.h> // to delete
#include <unistd.h>
#include <math.h> // to delete
// change the math functions with alternatives
#include <stdlib.h>
#include <fcntl.h> // to delete ?
#include "get_git/get_next_line_bonus.h"
#include "libft/libft.h"

// --------------checker.c--------------
void	process_model(char *str, int *stack_a, int *stack_b);

// --------stack_bonus_functions.c--------
void	swap_bonus(int *a, int *b, char x);
void	push_a_bonus(int *a, int *b);
void	push_b_bonus(int *a, int *b);
void	rotate_bonus(int *a, int *b, char x);
void	reverse_rotate_bonus(int *a, int *b, char x); 

# endif