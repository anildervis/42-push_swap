/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:38:15 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 20:14:17 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char static	*string[256];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string[fd] = read_from_text(fd, string[fd], 1);
	if (!string[fd] || ft_strlen_get(string[fd]) < 1)
	{
		free(string[fd]);
		string[fd] = NULL;
		return (NULL);
	}
	line = get_current_line(string[fd]);
	string[fd] = leftover_string(string[fd]);
	return (line);
}

char	*read_from_text(int fd, char *string, int count)
{
	char	*string_to_join;

	while (count > 0)
	{
		string_to_join = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		count = read(fd, string_to_join, BUFFER_SIZE);
		if (count < 0)
		{
			free(string_to_join);
			return (NULL);
		}
		string_to_join[count] = '\0';
		string = ft_strjoin_get(string, string_to_join);
		if (count < BUFFER_SIZE)
		{
			free(string_to_join);
			return (string);
		}
		if (ft_strchr(string, '\n'))
			break ;
		free(string_to_join);
	}
	free(string_to_join);
	return (string);
}

char	*leftover_string(char *string)
{
	int		i;
	int		line_length;
	int		last_length;
	char	*leftover_string;

	i = 0;
	line_length = 0;
	while (string[line_length] && string[line_length] != '\n')
		line_length++;
	if (string[line_length] == '\n')
		line_length++;
	last_length = ft_strlen_get(string) - line_length;
	leftover_string = (char *)malloc(sizeof(char) * (last_length + 1));
	while (i < last_length)
	{
		leftover_string[i] = string[line_length + i];
		i++;
	}
	leftover_string[i] = '\0';
	free(string);
	return (leftover_string);
}

char	*get_current_line(char *string)
{
	int		i;
	int		length;
	char	*line;

	i = 0;
	length = 0;
	while (string[length] && string[length] != '\n')
		length++;
	if (string[length])
		length++;
	line = (char *)malloc((length + 1) * sizeof(char));
	while (i < length)
	{
		line[i] = string[i];
		i++;
	}
	line[length] = '\0';
	return (line);
}

char	*ft_line(char *rt, char *rd)
{
	int		i;

	i = 0;
	if (!rd)
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (rd[i] == '\n')
		i++;
	rt = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (rd[i] && rd[i] != '\n')
	{
		rt[i] = rd[i];
		i++;
	}
	if (rd[i] == '\n')
		rt[i++] = '\n';
	rt[i] = 0;
	return (rt);
}
