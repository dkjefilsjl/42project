/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:43:09 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:08:01 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_data *list, int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->value = data;
	new->next = NULL;
	new->prev = NULL;
	new->id = 0;
	if (list->size == 0)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		new->prev = list->tail;
		list->tail->next = new;
		list->tail = new;
	}
	list->size++;
}

char	*check_space(char *s, int size)
{
	int		i;
	int		flag;
	char	*ch;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (!ft_strncmp(s, " ", size))
			flag = 1;
		i++;
	}
	if (flag == 0)
		ch = ft_strjoin(s, " ");
	else
		return (s);
	return (ch);
}

void	parse_data(t_data *list, int i, char *argv[])
{
	char		**data;
	long long	d;
	int			j;
	int			size;
	char		*s;

	j = -1;
	size = ft_strlen(argv[i]);
	s = check_space(argv[i], size);
	data = ft_split(s, ' ');
	if (!data)
		ft_exit("Error");
	while (data[++j])
	{
		ft_check_digit(data[j]);
		d = ft_atoi(data[j]);
		add_node(list, d);
	}
	free_ch(data);
	free(s);
	return ;
}

void	push_data_a(t_data *a, int argc, char *argv[])
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (++i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			ft_exit("Error");
	}
	i = 0;
	while (++i < argc)
		parse_data(a, i, argv);
}

void	sort_id(t_data *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				i->id++;
			else if (i->value < j->value)
				j->id++;
			else
				ft_exit("Error");
			j = j->next;
		}
		i = i->next;
	}
}
