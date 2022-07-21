/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:33:38 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:08:00 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_data *list)
{
	t_node	*new;

	if (list->size < 2)
		return ;
	new = list->head;
	list->head = new->next;
	new->next = list->head->next;
	new->prev = list->head;
	if (new->next)
		new->next->prev = new;
	else
		list->tail = new;
	list->head->prev = NULL;
	list->head->next = new;
}

void	ft_rotate(t_data *list)
{
	t_node	*new;

	if (list->size < 2)
		return ;
	new = list->head;
	new->next->prev = NULL;
	list->head = new->next;
	new->prev = list->tail;
	list->tail->next = new;
	new->next = NULL;
	list->tail = new;
}

void	ft_rrotate(t_data *list)
{
	t_node	*new;

	if (list->size < 2)
		return ;
	new = list->tail;
	list->tail = new->prev;
	new->next = list->head;
	list->head->prev = new;
	list->head = new;
	new->prev = NULL;
	list->tail->next = NULL;
}

void	ft_push(t_data *to, t_data *from)
{
	t_node	*new;

	if (from->size < 1)
		return ;
	if (to->size < 1)
	{
		ft_push_two(to, from);
	}
	else
	{
		to->size++;
		from->size--;
		new = to->head;
		new->prev = from->head;
		to->head = from->head;
		from->head = from->head->next;
		if (from->head)
			from->head->prev = NULL;
		new->prev->next = new;
		if (from->size == 0)
			from->tail = NULL;
	}
}

void	ft_push_two(t_data *to, t_data *from)
{
	to->head = from->head;
	to->tail = from->head;
	from->head = from->head->next;
	from->head->prev = NULL;
	to->head->next = NULL;
	if (from->size == 1)
		from->tail = NULL;
	to->size++;
	from->size--;
}
