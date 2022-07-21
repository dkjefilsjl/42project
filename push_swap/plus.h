/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:40:39 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:08:10 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLUS_H
# define PLUS_H
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647

typedef struct s_node
{
	int				value;
	int				id;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_data
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_data;

void		ft_swap(t_data *list);
void		ft_rotate(t_data *list);
void		ft_rrotate(t_data *list);
void		ft_push(t_data *to, t_data *from);
void		ft_push_two(t_data *to, t_data *from);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
long long	ft_atoi(const char *str);
void		ft_check_digit(char *str);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr(char *s);
char		*ft_strjoin(char *s1, char *s2);
void		ft_exit(char *s);
void		init_ab(t_data *td);
void		free_node(t_data *list);
void		free_ch(char **ch);
void		add_node(t_data *list, int data);
char		*check_space(char *s, int size);
void		push_data_a(t_data *a, int argc, char *argv[]);
void		parse_data(t_data *list, int i, char *argv[]);
int			prev_sorted(t_data *a);
char		**ft_split(char const *s, char c);
void		sort_id(t_data *a);

#endif
