/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:32:32 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:08:08 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "plus.h"

void		sand_algo(t_data *a, t_data *b);
void		push_swap(char *c, t_data *a, t_data *b);
void		arse_data(t_data *list, int i, char *argv[]);
void		free_nodes(t_data *list);
void		size_three_sort(t_data *a);
void		size_four_sort(t_data *a, t_data *b);
void		size_five_sort(t_data *a, t_data *b);
void		size_any_sort(t_data *a, t_data *b);
void		choose_ra_rra(t_data *a, int size);
void		choose_rb_rrb(t_data *b, int size);
void		size_any_sort_two(t_data *a, t_data *b);

#endif
