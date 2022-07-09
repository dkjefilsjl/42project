/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:28:11 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/05 00:27:06 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_put(char **t, char const *str, int k, char charset);
static int	ft_count(char const *str, char charset);
static void	ft_free(char ***t, int j);
static void	ft_hate_line(char **t, int j, int size);

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		k;
	int		count;
	int		re;

	re = 0;
	k = 0;
	if (!s)
		return (0);
	count = ft_count(s, c);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == 0)
		return (0);
	re = ft_put(t, s, k, c);
	if (re == 0)
		t[0] = 0;
	else
		t[re] = 0;
	return (t);
}

static int	ft_put(char **t, char const *str, int k, char charset)
{
	int	size;
	int	i;
	int	j;

	j = 0;
	size = 1;
	i = -1;
	while (++i < (int)ft_strlen(str))
	{
		if ((str[i] == charset) \
				|| (str[i + 1] == '\0' && i++ && size++))
		{
			if (size > 1)
			{
				k = ++size;
				ft_hate_line(t, j, size);
				while (--size > 1)
					t[j][k - size - 1] = str[i - size + 1];
				t[j++][k - 2] = '\0';
			}
		}
		else
			size++;
	}
	return (j);
}

static void	ft_hate_line(char **t, int j, int size)
{
	t[j] = (char *)malloc(sizeof(char) * (size));
	if (!t[j])
		ft_free(&t, j);
}

static int	ft_count(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (charset == str[i])
		{
			if (i != 0 && (charset != str[i - 1]))
			{
				count++;
			}
		}
		else if (str[i + 1] == '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

static void	ft_free(char ***t, int j)
{
	j = j - 1;
	while (j >= 0)
	{
		free((*t)[j]);
		j--;
	}
	free(*t);
	*t = NULL;
}
