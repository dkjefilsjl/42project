/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:33:08 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:08:06 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	init_ab(t_data *td)
{
	td->head = NULL;
	td->tail = NULL;
	td->size = 0;
}

void	free_node(t_data *list)
{
	t_node	*new;

	while (list->head)
	{
		new = list->head;
		list->head = list->head->next;
		free(new);
	}
	list->size = 0;
	list->tail = NULL;
}

void	free_ch(char **ch)
{
	int	i;

	i = 0;
	while (ch[i])
	{
		free(ch[i]);
		i++;
	}
	free(ch);
}

int	prev_sorted(t_data *a)
{
	t_node	*i;

	i = a->head;
	while (i->next)
	{
		if (i->id > i->next->id)
			return (0);
		i = i->next;
	}
	return (1);
}
