/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:30:12 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:10:48 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	push_swap_checker(char *c, t_data *a, t_data *b)
{
	if (!ft_strncmp(c, "sa\n", 3))
		ft_swap(a);
	else if (!ft_strncmp(c, "sb\n", 3))
		ft_swap(b);
	else if (!ft_strncmp(c, "ss\n", 3))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strncmp(c, "pa\n", 3))
		ft_push(a, b);
	else if (!ft_strncmp(c, "pb\n", 3))
		ft_push(b, a);
	else if (!ft_strncmp(c, "ra\n", 3))
		ft_rotate(a);
	else if (!ft_strncmp(c, "rb\n", 3))
		ft_rotate(b);
	else if (!ft_strncmp(c, "rr\n", 3))
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else
		push_swap_checker_two(c, a, b);
}

void	push_swap_checker_two(char *c, t_data *a, t_data *b)
{
	if (!ft_strncmp(c, "rra\n", 4))
		ft_rrotate(a);
	else if (!ft_strncmp(c, "rrb\n", 4))
		ft_rrotate(b);
	else if (!ft_strncmp(c, "rrr\n", 4))
	{
		ft_rrotate(a);
		ft_rrotate(b);
	}
	else
		ft_exit("Error");
}

void	ft_checker(t_data *a, t_data *b)
{
	char	*st;

	st = get_next_line(0);
	while (st)
	{
		free(st);
		push_swap_checker(st, a, b);
		st = get_next_line(0);
	}
	if (!((b->size == 0) && (b->head == NULL) \
		&& (b->tail == NULL)) || !prev_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
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
	ft_checker(&a, &b);
	free_node(&a);
	free_node(&b);
	return (0);
}
