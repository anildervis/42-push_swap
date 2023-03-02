/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderviso <aderviso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:01:43 by aderviso          #+#    #+#             */
/*   Updated: 2023/03/02 15:04:24 by aderviso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long int	number;
	int				sign;

	number = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		error();
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			number = (number * 10) + (*str - '0') * sign;
			str++;
			if (number > 2147483647 || number < -2147483648)
				error();
		}
		else
			error();
	}
	return (number);
}
