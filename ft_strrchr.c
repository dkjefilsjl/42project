/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:39:20 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 18:40:36 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int	c)
{
	int		i;
	char	cc;

	i = ft_strlen(s);
	cc = (char) c;
	while (i >= 0)
	{
		if (cc == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return ((char *) NULL);
}
