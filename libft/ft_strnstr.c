/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:17:34 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 18:39:01 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_check(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lh;
	size_t	ln;
	int		i;

	lh = ft_strlen(haystack);
	ln = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if ((lh < ln) || (len < ln))
		return (0);
	else
	{
		i = ft_check(haystack, needle, len);
		if (i != -1)
			return ((char *)&haystack[i]);
	}
	return ((void *) NULL);
}

static int	ft_check(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;
	size_t	ln;

	i = 0;
	ln = ft_strlen(needle);
	while (((size_t)i < len) && (haystack[i]))
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while ((((size_t)i + j) < len) && (j < ln) \
					&& (haystack[i + j] == needle[j]))
				j++;
		}
		if (j == ln)
			return (i);
		i++;
	}
	return (-1);
}
