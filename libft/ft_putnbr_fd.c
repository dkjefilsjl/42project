/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:13:57 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 17:54:12 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int nb, int fd);
static int	ft_minus(int nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	ft_putnbr(n, fd);
}

static void	ft_putnbr(int nb, int fd)
{
	char	c;

	nb = ft_minus(nb, fd);
	if (nb < 10)
	{
		c = nb + 48;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
}

static int	ft_minus(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2", 2);
		nb = 147483648;
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	return (nb);
}
