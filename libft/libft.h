#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h> // to delete
#include <unistd.h>
#include <math.h> // to delete
// change the math functions with alternatives
#include <stdlib.h>
#include <fcntl.h> // to delete ?

char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);
void *ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);

# endif
