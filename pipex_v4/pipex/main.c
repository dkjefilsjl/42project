/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:38:40 by seoyepar          #+#    #+#             */
/*   Updated: 2022/06/20 21:40:33 by seoyepar         ###   ########.fr       */
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

	if (argc == 5)
	{
		f[0] = open(argv[1], O_RDONLY);
		f[1] = open(argv[4], O_WRONLY | O_CREAT, 0644 | O_TRUNC);
		if ((f[0] < 0) || (f[1] < 0))
			return (ft_putstr_fd("file open error", 1));
		ft_pipex(argc, argv, f, envp);
		if (close(f[0]) < 0 || close(f[1]) < 0)
			return (ft_putstr_fd("file close error", 1));
	}
	else
		return (ft_putstr_fd("I want argc == 4! check one more time", 1));
	return (0);
}
