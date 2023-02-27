#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // to delete
#include <unistd.h>
#include <math.h> // to delete
// change the math functions with alternatives
#include <stdlib.h>
#include <fcntl.h> // to delete ?
#include "get_git/get_next_line_bonus.h"


// ----------stack_functions.c------------
void swap(int *a, int *b, char x);
void push_a(int *a, int *b);
void push_b(int *a, int *b);
void rotate(int *a, int *b, char x);
void reverse_rotate(int *a, int *b, char x); 

// -----------stack_read.c----------------
int *argument_get(int argc, char **argv);
int *stack_converter(char *str);
int *indexing(int *list);

// -------------sorting.c-----------------
void seperating_into_stacks(int *stack_a, int *stack_b);
void send_all_b(int *stack_a, int *stack_b);
int ft_max_index(int *stack);
int ft_min_index(int *stack);

int road_to_smallest_bigger_index(int *stack_a, int *stack_b, int position);
void double_rotate(int a_road, int b_road, int *stack_a, int *stack_b);
void double_reverse_rotate(int a_road, int b_road, int *stack_a, int *stack_b);
void on_my_way(int a_road, int b_road, int *stack_a, int *stack_b);
void send_all_a(int *stack_a, int *stack_b, int *stack_c);

void sort_three(int *stack_a, int *stack_b);
void sort_four(int *stack_a, int *stack_b);
void sort_five(int *stack_a, int *stack_b);
int is_sorted(int *stack);
void last_sort(int *stack_a, int *stack_b);

# endif