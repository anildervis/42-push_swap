#include "push_swap.h"

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
	// getting arguments with tabs between them
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	// + veya - kullanımı var mı diye checker kontrolü
	// eğer varsa -, +'dan sonraki ifadenin null olmamasına dikkat et 
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			number = (number * 10) + (*str - '0') * sign;
			str++;
			if (number > 2147483647)
				exit(1); // error message on stderror
			if (number < -2147483648)
				exit(1); // is it alright to use negative numbers?
		}
		else
			exit(1); // error message on stderror
	}
	return (number);
}