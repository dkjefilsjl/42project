/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:57:28 by seoyepar          #+#    #+#             */
/*   Updated: 2022/06/22 21:58:41 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ch;
	unsigned char	*sch;
	int				i;

	if (!dst && !src)
		return (0);
	i = 0;
	ch = (unsigned char *)dst;
	sch = (unsigned char *)src;
	while (n)
	{
		ch[i] = sch[i];
		i++;
		n--;
	}
	return (dst);
}

void	init_pc(t_pc *pc)
{
	pc->cmd = 0;
	pc->path = 0;
	pc->options = 0;
}

int	check_cmd(t_pc *pc)
{
	int		i;
	char	*cmd;

	i = 0;
	while (pc->path[i])
	{
		cmd = ft_strjoin(pc->path[i++], "/");
		cmd = ft_strjoin(cmd, pc->cmd);
		if (!cmd)
			return (0);
		if (access(cmd, F_OK) == 0)
		{
			free(cmd);
			return (1);
		}
		free(cmd);
	}
	return (0);
}

void	ft_putstr_fd_two(char *s, int fd)
{
		if (!s || (fd < 0))
				exit(1);
			write(fd, s, ft_strlen(s));
				exit(1);
}
