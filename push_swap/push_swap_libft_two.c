/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_libft_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:38:37 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:07:57 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
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
	return (ch);
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
