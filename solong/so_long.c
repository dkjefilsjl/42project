/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:07:48 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/05 03:34:35 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init(t_sl *sl)
{
	int	img_width;
	int	img_height;

	sl->height = 0;
	sl->width = 0;
	sl->w_cnt = 0;
	sl->c_cnt = 0;
	sl->x = 0;
	sl->y = 0;
	sl->bone = mlx_xpm_file_to_image(sl->mlx, "./img/bone.xpm", \
			&img_width, &img_height);
	sl->dog = mlx_xpm_file_to_image(sl->mlx, "./img/dog.xpm", \
			&img_width, &img_height);
	sl->fence = mlx_xpm_file_to_image(sl->mlx, "./img/fence.xpm", \
			&img_width, &img_height);
	sl->fence2 = mlx_xpm_file_to_image(sl->mlx, "./img/fence2.xpm", \
			&img_width, &img_height);
	sl->grass = mlx_xpm_file_to_image(sl->mlx, "./img/grass.xpm", \
			&img_width, &img_height);
	sl->house = mlx_xpm_file_to_image(sl->mlx, "./img/house.xpm", \
			&img_width, &img_height);
}

void	gnl_map(char *f, t_sl *sl)
{
	int		fd;
	char	*line;

	fd = open(f, O_RDONLY);
	if (fd <= 0)
		ft_exit("File open error\n");
	line = get_next_line(fd);
	if (line == 0)
		ft_exit("nothing! file check please.\n");
	sl->st = ft_strdup(line);
	sl->width = ft_strlen(line) - 1;
	free(line);
	while (line)
	{
		sl->height++;
		line = get_next_line(fd);
		if (line)
			sl->st = ft_strjoin(sl->st, line);
	}
	close(fd);
}

void	match_img(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->board[i])
	{
		j = 0;
		while (sl->board[i][j])
		{
			match_window(sl, i, j);
			j++;
		}
		i++;
	}
}

void	match_window(t_sl *sl, int i, int j)
{
	mlx_put_image_to_window(sl->mlx, sl->win, \
		sl->grass, j * 50, i * 50);
	if (sl->board[i][j] == '1')
		mlx_put_image_to_window(sl->mlx, sl->win, \
			sl->fence, j * 50, i * 50);
	else if (sl->board[i][j] == 'P')
	{
		mlx_put_image_to_window(sl->mlx, sl->win, \
		sl->dog, j * 50, i * 50);
		sl->x = i;
		sl->y = j;
	}
	else if (sl->board[i][j] == 'E')
		mlx_put_image_to_window(sl->mlx, sl->win, \
		sl->house, j * 50, i * 50);
	else if (sl->board[i][j] == 'C')
		mlx_put_image_to_window(sl->mlx, sl->win, \
		sl->bone, j * 50, i * 50);
}

int	main(int argc, char *argv[])
{
	t_sl	*sl;

	if (argc != 2)
		ft_exit("argc == 2. map upload please!");
	sl = malloc(sizeof(t_sl));
	sl->mlx = mlx_init();
	sl_init(sl);
	gnl_map(argv[1], sl);
	check_map(sl);
	sl->win = mlx_new_window(sl->mlx, 50 * sl->width, \
		50 * sl->height, "so_long");
	match_img(sl);
	mlx_hook(sl->win, 2, 0, &check_key, sl);
	mlx_hook(sl->win, 17, 0, &ft_exit_sl, sl);
	mlx_loop(sl->mlx);
	return (0);
}
