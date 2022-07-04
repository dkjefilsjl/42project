/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:10:47 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/05 03:22:42 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_move(t_sl *sl, int i, int j)
{
	if (sl->board[sl->x + i][sl->y + j] == 'C')
		sl->c_cnt--;
	if (sl->board[sl->x + i][sl->y + j] == 'E' && (sl->c_cnt == 0))
		finish(sl);
	else if (sl->board[sl->x + i][sl->y + j] != '1' \
			&& sl->board[sl->x + i][sl->y + j] != 'E')
	{
		sl->w_cnt++;
		printf("walk count = %d\n", sl->w_cnt);
		sl->board[sl->x][sl->y] = '0';
		sl->board[sl->x + i][sl->y + j] = 'P';
		match_img(sl);
	}
}

void	check_map(t_sl *sl)
{
	int	i;

	i = 0;
	sl->board = ft_split(sl->st, '\n');
	while (sl->board[i])
	{
		if ((int)ft_strlen(sl->board[i++]) != sl->width)
			ft_exit("Your Map is not rectangular\n");
	}
	check_map_wall(sl);
	check_map_ess(sl);
}

void	check_map_wall(t_sl *sl)
{
	int	i;

	i = 0;
	while (sl->board[0][i])
	{
		if (sl->board[0][i] != '1')
			ft_exit("Map wall error1\n");
		i++;
	}
	i = 0;
	while (sl->board[i])
	{
		if ((sl->board[i][0] != '1') || (sl->board[i][sl->width - 1] != '1'))
			ft_exit("Map wall error2\n");
		i++;
	}
	i = 0;
	while (sl->board[sl->height - 1][i])
	{
		if (sl->board[sl->height - 1][i] != '1')
			ft_exit("Map wall error3\n");
		i++;
	}
}

void	check_map_ess(t_sl *sl)
{
	int	i;
	int	count_p;
	int	count_e;

	i = 0;
	count_p = 0;
	count_e = 0;
	while (sl->st[i])
	{
		if (sl->st[i] == 'P')
			count_p++;
		else if (sl->st[i] == 'C')
			sl->c_cnt++;
		else if (sl->st[i] == 'E')
			count_e++;
		else if (sl-> st[i] == '1' || sl->st[i] == '0')
			;
		else if (sl-> st[i] != '\n')
			ft_exit("The map has invalid elements\n");
		i++;
	}
	if (count_p != 1)
		ft_exit("Map error. P is not exist\n");
	else if (count_e < 1 || sl->c_cnt < 1)
		ft_exit("Map error. we need exit >= 1 && collection >= 1\n");
}

void	finish(t_sl *sl)
{
	sl->w_cnt++;
	printf("You are very smart! Game finish\n");
	exit(0);
}
