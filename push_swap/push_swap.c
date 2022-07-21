/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:33:50 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:07:25 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sand_algo(t_data *a, t_data *b)
{
	if (a->size == 2)
		push_swap("sa", a, b);
	else if (a->size == 3)
		size_three_sort(a);
	else if (a->size == 4)
		size_four_sort(a, b);
	else if (a->size == 5)
		size_five_sort(a, b);
	else
	{
		size_any_sort(a, b);
	}
}

void	push_swap(char *c, t_data *a, t_data *b)
{
	if (!ft_strncmp(c, "sa", 2))
		ft_swap(a);
	if (!ft_strncmp(c, "sb", 2))
		ft_swap(b);
	if (!ft_strncmp(c, "pa", 2))
		ft_push(a, b);
	if (!ft_strncmp(c, "pb", 2))
		ft_push(b, a);
	if (!ft_strncmp(c, "ra", 2))
		ft_rotate(a);
	if (!ft_strncmp(c, "rb", 2))
		ft_rotate(b);
	if (!ft_strncmp(c, "rra", 3))
		ft_rrotate(a);
	if (!ft_strncmp(c, "rrb", 3))
		ft_rrotate(b);
	ft_putstr(c);
}

int	main(int argc, char *argv[])
{
	t_data	a;
	t_data	b;

	if (argc < 2)
		return (0);
	init_ab(&a);
	init_ab(&b);
	push_data_a(&a, argc, argv);
	sort_id(&a);
	if (prev_sorted(&a))
	{
		free_node(&a);
		free_node(&b);
		return (0);
	}
	sand_algo(&a, &b);
	free_node(&a);
	free_node(&b);
	return (0);
}
