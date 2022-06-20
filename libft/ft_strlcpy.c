/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:17:00 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 18:23:31 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	re;

	i = 0;
	re = 0;
	while (src[re])
		re++;
	while ((dstsize > 1) && src[i])
	{
		dst[i] = src[i];
		dstsize--;
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (re);
}
