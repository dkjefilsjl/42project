/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:28:17 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/11 19:22:31 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ch;
	unsigned char	*sch;
	int		i;

	if (!dst && !src)
		return (0);
	i = 0;
	ch = (unsigned char *)dst;
	sch = (unsigned char *)src;
	while (n)
	{
		ch[i] = sch[i];
		i++;
		n--;
	}
	return (dst);
}
