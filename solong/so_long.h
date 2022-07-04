/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:15:22 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/05 03:15:47 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# define BUFFER_SIZE 5
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_solong{
	void	*mlx;
	void	*win;
	int		w_cnt;
	int		width;
	int		height;
	int		c_cnt;
	int		x;
	int		y;
	void	*bone;
	void	*dog;
	void	*fence;
	void	*fence2;
	void	*grass;
	void	*house;
	char	*st;
	char	**board;
}	t_sl;

void	sl_init(t_sl *sl);
void	gnl_map(char *f, t_sl *sl);
size_t	ft_strlen(const char *s);
void	ft_exit(char *s);
void	check_map(t_sl *sl);
void	check_map_wall(t_sl *sl);
void	check_map_ess(t_sl *sl);
int		check_key(int key, t_sl *sl);
void	key_move(t_sl *sl, int i, int j);
void	finish(t_sl *sl);
int		ft_exit_sl(t_sl *sl);
void	match_img(t_sl *sl);

int		check_new_line(char *r_line);
char	*print_line(int new_line, char **r_line);
char	*free_line(char **r_line);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_two(int size, char *str, char **r_line, int fd);
char	**ft_split(char const *s, char c);

#endif
