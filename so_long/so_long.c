/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:07:48 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/06 18:15:11 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init(t_sl *sl, char *argv[])
{
	sl->height = 0;
	sl->width = 0;
	sl->w_cnt = 0;
	sl->c_cnt = 0;
	sl->x = 0;
	sl->y = 0;
	sl_init_img(sl);
	gnl_map(argv[1], sl);
	check_map(sl);
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
	if (!sl->st)
		ft_exit("malloc error\n");
	sl->width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		sl->height++;
		line = get_next_line(fd);
		if (line)
			sl->st = ft_strjoin(sl->st, line);
		if (!sl->st)
			ft_exit("malloc error\n");
	}
	free(line);
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
	int		len;

	if (argc != 2)
		ft_exit("argc == 2. map upload please!");
	len = ft_strlen(argv[1]);
	if ((len < 5) || (ft_strncmp(argv[1] + (len - 4), ".ber", 4) != 0))
		ft_exit("please give me .ber map");
	sl = malloc(sizeof(t_sl));
	if (!sl)
		ft_exit("malloc error");
	sl->mlx = mlx_init();
	if (!sl->mlx)
		ft_exit("mlx error");
	sl_init(sl, argv);
	sl->win = mlx_new_window(sl->mlx, 50 * sl->width, \
		50 * sl->height, "so_long");
	if (!sl->win)
		ft_exit("mlx error");
	match_img(sl);
	mlx_hook(sl->win, 2, 0, &check_key, sl);
	mlx_hook(sl->win, 17, 0, &ft_exit_sl, sl);
	mlx_loop(sl->mlx);
	return (0);
}
