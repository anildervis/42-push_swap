/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:48:00 by aderviso          #+#    #+#             */
/*   Updated: 2023/02/27 13:55:42 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_get(char *string)
{
	int	i;

	i = 0;
	if (string == (void *)0)
		return (0);
	while (string[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	size_t	i;

	i = 0;
	a = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	a = (void *) malloc(size * count);
	if (!a)
		return (0);
	ft_bzero(a, size * count);
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s1 == (void *)0)
		s1 = ft_calloc(1, 1);
	str = malloc(sizeof(char) * (ft_strlen_get(s1) + ft_strlen_get(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	free(s1);
	str[i + k] = 0;
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
