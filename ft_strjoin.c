/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:07:38 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 18:17:27 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ch;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	ch = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ch)
		return (0);
	ft_memcpy(ch, s1, ft_strlen(s1));
	ft_memcpy(&ch[ft_strlen(s1)], s2, ft_strlen(s2));
	ch[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ch);
}
