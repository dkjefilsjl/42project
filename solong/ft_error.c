/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:07:25 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/05 03:32:58 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *s)
{
	printf("%s", s);
	exit(1);
}

int	ft_exit_sl(t_sl *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit(0);
}

int	check_key(int key, t_sl *sl)
{
	if (key == KEY_ESC)
		ft_exit_sl(sl);
	if (key == KEY_W)
		key_move(sl, -1, 0);
	if (key == KEY_A)
		key_move(sl, 0, -1);
	if (key == KEY_S)
		key_move(sl, 1, 0);
	if (key == KEY_D)
		key_move(sl, 0, 1);
	return (0);
}
