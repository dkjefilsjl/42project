#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	num;
	int			neg;

	neg = 1;
	num = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		if ((neg == -1 && num - 1 > INT_MAX) \
		|| (neg == 1 && num > INT_MAX))
			ft_exit("Error\n");
	}
	return (num * neg);
}

void	ft_check_digit(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			ft_exit("Error\n");
		if ((str[i] == '+' || str[i] == '-') && \
			((i == len - 1) || !ft_isdigit(str[i + 1])))
			ft_exit("Error\n");
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			ft_exit("Error\n");
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}