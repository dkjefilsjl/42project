/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:52:15 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/06 18:15:06 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *s)
{
	printf("%s", s);
	exit(1);
}

int	ft_exit_sl(void)
{
	printf("exit game!");
	exit(0);
}

int	check_key(int key, t_sl *sl)
{
	if (key == KEY_ESC)
		ft_exit_sl();
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		i++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}

void	sl_init_img(t_sl *sl)
{
	int	img_width;
	int	img_height;

	sl->bone = mlx_xpm_file_to_image(sl->mlx, "./img/bone.xpm", \
			&img_width, &img_height);
	if (!sl->bone)
		ft_exit("img upload error");
	sl->dog = mlx_xpm_file_to_image(sl->mlx, "./img/dog.xpm", \
			&img_width, &img_height);
	if (!sl->dog)
		ft_exit("img upload error");
	sl->fence = mlx_xpm_file_to_image(sl->mlx, "./img/fence.xpm", \
			&img_width, &img_height);
	if (!sl->fence)
		ft_exit("img upload error");
	sl->grass = mlx_xpm_file_to_image(sl->mlx, "./img/grass.xpm", \
			&img_width, &img_height);
	if (!sl->grass)
		ft_exit("img upload error");
	sl->house = mlx_xpm_file_to_image(sl->mlx, "./img/house.xpm", \
			&img_width, &img_height);
	if (!sl->house)
		ft_exit("img upload error");
}
