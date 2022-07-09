/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:19:30 by seoyepar          #+#    #+#             */
/*   Updated: 2022/03/26 14:19:45 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

#endif
