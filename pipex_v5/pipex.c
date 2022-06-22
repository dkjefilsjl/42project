/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:40:47 by seoyepar          #+#    #+#             */
/*   Updated: 2022/06/22 22:03:22 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipex(int argc, char **argv, int *f, char **envp)
{
	int		i;
	t_pc	pc[2];

	i = 1;
	while (++i < argc - 1)
	{
		init_pc(&(pc[i - 2]));
		if (!get_pc(&(pc[i - 2]), argv[i], envp))
		{
			free_struct(&(pc[i - 2]));
			return (0);
		}
		if (!check_cmd(&(pc[i - 2])))
		{
			free_struct(&(pc[i - 2]));
			ft_putstr_fd("zsh: command not found: ", 1);
			ft_putstr_fd(argv[i], 1);
			ft_putstr_fd_two("\n", 1);
		}
	}
	go_pipex(f, envp, pc);
	i = 0;
	while (i < 2)
		free_struct(&(pc[i++]));
	return (0);
}

void	free_struct(t_pc *pc)
{
	if (pc->cmd)
		free(pc->cmd);
	if (pc->path)
		free_arr(pc->path);
	if (pc->options)
		free_arr(pc->options);
}

int	get_pc(t_pc *pc, char *argv, char **envp)
{
	pc->path = find_path(envp);
	if (!pc->path)
		return (0);
	pc->options = ft_split(argv, ' ');
	if (!pc->options)
		return (0);
	if (pc->options[0] == NULL)
	{
		ft_putstr_fd("zsh: command not found: ", 1);
		ft_putstr_fd(argv, 1);
		ft_putstr_fd_two("\n", 1);
	}
	pc->cmd = ft_strdup(pc->options[0]);
	if (!pc->cmd)
	{
		free_arr(pc->options);
		return (0);
	}
	return (1);
}

void	free_arr(char **st)
{
	int	i;

	i = 0;
	while (st[i])
	{
		free(st[i]);
		i++;
	}
	if (st)
		free(st);
}

char	**find_path(char **envp)
{
	int		i;
	char	*_path;
	char	**re;

	i = 2;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			_path = ft_strdup(envp[i] + 5);
			if (!_path)
				return (NULL);
			re = ft_split(_path, ':');
			if (!re)
			{
				free(_path);
				return (NULL);
			}
			free (_path);
			return (re);
		}
		i++;
	}
	return (0);
}
