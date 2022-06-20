/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:58:11 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 19:26:15 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ch;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	ch = (char *)malloc(sizeof(char) * i + 1);
	if (!ch)
		return (0);
	i = 0;
	while (s1[i])
	{
		ch[i] = s1[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
