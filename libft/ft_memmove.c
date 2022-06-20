/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:58:19 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 17:45:19 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	loc;

	if ((dest == NULL && src == NULL) || (n < 0))
		return (0);
	else if (dest < src)
	{
		i = -1;
		while ((size_t)++i < n)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		if (n == 0)
			return (dest);
		loc = n - 1;
		while (loc > 0)
		{
			((unsigned char *)dest)[loc] = ((unsigned char *)src)[loc];
			loc--;
		}
		((unsigned char *)dest)[0] = ((unsigned char *)src)[0];
	}
	return (dest);
}
