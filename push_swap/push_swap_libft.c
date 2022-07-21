/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:32:56 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:07:58 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ft_exit("Error");
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
			ft_exit("Error");
		if ((str[i] == '+' || str[i] == '-') && \
			((i == len - 1) || !ft_isdigit(str[i + 1])))
			ft_exit("Error");
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			ft_exit("Error");
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		i++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}
