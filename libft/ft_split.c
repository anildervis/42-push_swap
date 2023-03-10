/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:01:50 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 20:13:50 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_split(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				i;
	unsigned int	length;

	i = 0;
	length = ft_strlen_split(s);
	if (start > length)
		return (NULL);
	if ((length - start + 1) >= len)
		str = malloc(sizeof(char) * (len + 1));
	if ((length - start + 1) < len)
		str = malloc(sizeof(char) * (length - start + 2));
	if (!str)
		return (NULL);
	while (s[start + i] && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	if (*s == '\0')
		error();
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		start_point;
	char	**splitted;

	i = 0;
	k = 0;
	splitted = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!splitted)
		return (0);
	while (s[k])
	{
		while (s[k] && s[k] == c)
			k++;
		if (s[k] && s[k] != c)
			start_point = k;
		while (s[k] && s[k] != c)
			k++;
		if (ft_wordcount(s, c) != i)
			splitted[i++] = ft_substr(s, start_point, k - start_point);
	}
	splitted[i] = 0;
	return (splitted);
}
