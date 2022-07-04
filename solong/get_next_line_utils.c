/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:46:11 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/04 22:52:22 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ch;

	i = 0;
	if (!s1)
		return (0);
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

char	*ft_strjoin(char *s1, char *s2)
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ch;
	unsigned char	*sch;
	int				i;

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
