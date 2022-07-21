/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:32:45 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:08:03 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_any_sort(t_data *a, t_data *b)
{
	int		chunk;
	int		size;
	int		num;

	num = 0;
	size = a->size;
	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	while (a->size)
	{
		if (a->head->id <= num)
		{
			push_swap("pb", a, b);
			num++;
		}
		else if (a->head->id <= num + chunk)
		{
			push_swap("pb", a, b);
			push_swap("rb", NULL, b);
			num++;
		}
		else
			choose_ra_rra(a, chunk + num);
	}
	size_any_sort_two(a, b);
}

void	choose_ra_rra(t_data *a, int size)
{
	if (a->tail->id <= size)
		push_swap("rra", a, NULL);
	else
		push_swap("ra", a, NULL);
}

void	choose_rb_rrb(t_data *b, int size)
{
	int		pos;
	t_node	*new;

	pos = 1;
	new = b->head;
	while (new->id != size)
	{
		pos++;
		new = new->next;
	}
	if (pos <= b->size / 2)
	{
		while (b->head->id != size)
			push_swap("rb", NULL, b);
	}
	else
	{
		while (b->head->id != size)
			push_swap("rrb", NULL, b);
	}
}

void	size_any_sort_two(t_data *a, t_data *b)
{
	int	size;

	while (b->size)
	{
		size = b->size - 1;
		choose_rb_rrb(b, size);
		push_swap("pa", a, b);
	}
}
