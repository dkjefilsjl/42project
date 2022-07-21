/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:30:40 by seoyepar          #+#    #+#             */
/*   Updated: 2022/07/15 05:07:33 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "plus.h"
# include <limits.h>
# define BUFFER_SIZE 5

char	*ft_strdup(const char *s1);
void	ft_checker(t_data *a, t_data *b);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		check_new_line(char *r_line);
char	*print_line(int new_line, char **r_line);
char	*free_line(char **r_line);
char	*get_next_two(int size, char *str, char **r_line, int fd);
char	*get_next_line(int fd);
void	push_swap_checker(char *c, t_data *a, t_data *b);
void	push_swap_checker_two(char *c, t_data *a, t_data *b);

#endif