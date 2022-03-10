/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:40:47 by seoyepar          #+#    #+#             */
/*   Updated: 2022/01/17 18:57:44 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set);
static int	ft_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ch;
	int		len;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	ch = (char *)malloc(sizeof(char) * len + 1);
	if (!ch)
		return (0);
	ft_memmove(ch, &s1[start], len);
	ch[len] = '\0';
	return (ch);
}

static int	ft_start(char const *s1, char const *set)
{
	int		i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			else
				j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int		i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i--;
				break ;
			}
			else
				j++;
		}
		if ((j == ft_strlen(set)) || (i < 0))
			break ;
	}
	return (i);
}
