/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:40:02 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:07:45 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

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

char	*ft_strjoin_gnl(char *s1, char *s2)
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
	free((void *)s1);
	return (ch);
}
