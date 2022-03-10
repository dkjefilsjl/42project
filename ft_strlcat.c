/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:24:12 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 18:19:50 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	slen;
	size_t	dlen;

	j = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (size == 0)
		return (slen);
	if (dlen >= size)
		return ((slen + size));
	i = dlen;
	while ((i + 1 < size) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return ((slen + dlen));
}
