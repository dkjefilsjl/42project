/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:38:40 by seoyepar          #+#    #+#             */
/*   Updated: 2022/06/22 22:10:11 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int	f[2];
	int	n;

	if (argc == 5)
	{
		f[0] = open(argv[1], O_RDONLY);
		f[1] = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if ((f[0] < 0) || (f[1] < 0))
			ft_putstr_fd_two("file open error", 1);
		n = ft_pipex(argc, argv, f, envp);
		if (close(f[0]) < 0 || close(f[1]) < 0)
			ft_putstr_fd_two("file close error", 1);
	}
	else
		ft_putstr_fd_two("I want argc == 4! check one more time", 1);
	return (0);
}
