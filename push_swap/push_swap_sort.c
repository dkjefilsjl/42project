/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:33:58 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:08:05 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_three_sort(t_data *a)
{
	int	new;
	int	new2;
	int	new3;

	new3 = a->head->id;
	new = a->head->next->id;
	new2 = a->head->next->next->id;
	if (prev_sorted(a))
		return ;
	if ((new3 == new - 2) && (new3 == new2 - 1))
	{
		push_swap("sa", a, NULL);
		push_swap("ra", a, NULL);
	}
	if ((new3 == new + 1) && (new3 == new2 - 1))
		push_swap("sa", a, NULL);
	if ((new3 == new - 1) && (new3 == new2 + 1))
		push_swap("rra", a, NULL);
	if ((new3 == new + 2) && (new3 == new2 + 1))
		push_swap("ra", a, NULL);
	if ((new3 == new + 1) && (new3 == new2 + 2))
	{
		push_swap("sa", a, NULL);
		push_swap("rra", a, NULL);
	}
}

void	size_four_sort(t_data *a, t_data *b)
{
	while (a->size > 3)
	{
		if (a->head->id == 0)
		{
			push_swap("pb", a, b);
			break ;
		}
		else
			push_swap("ra", a, b);
	}
	size_three_sort(a);
	push_swap("pa", a, b);
}

void	size_five_sort(t_data *a, t_data *b)
{
	while (a->size > 3)
	{
		if (a->head->id < 2)
			push_swap("pb", a, b);
		else
			push_swap("ra", a, b);
	}
	size_three_sort(a);
	while (b->size)
		push_swap("pa", a, b);
	if (a->head->id != 0)
		push_swap("sa", a, b);
}
