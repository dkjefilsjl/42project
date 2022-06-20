/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:54:50 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 17:46:52 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;
	int		i;

	ch = (unsigned char *)b;
	i = 0;
	while (len)
	{
		ch[i++] = c;
		len--;
	}
	return (b);
}
