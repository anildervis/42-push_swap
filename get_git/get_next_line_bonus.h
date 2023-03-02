/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:46:15 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 20:14:38 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc_get(size_t count, size_t size);
char	*ft_strjoin_get(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
char	*read_from_text(int fd, char *string, int count);
int		ft_strlen_get(char *string);
char	*leftover_string(char *string);
char	*get_current_line(char *string);
void	ft_bzero_get(void *s, size_t n);

#endif
