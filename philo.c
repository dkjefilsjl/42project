/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:40:08 by seoyepar          #+#    #+#             */
/*   Updated: 2022/09/02 03:32:21 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ar_check(int argc, char **argv, t_argu *argu)
{
	int	check;

	check = 0;
	if ((argc != 5) && (argc != 6))
		return (-1);
	argu->numofphilo = ft_atoi(argv[1]);
	argu->time_to_die = ft_atoi(argv[2]);
	argu->time_to_eat = ft_atoi(argv[3]);
	argu->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		argu->must_eat = ft_atoi(argv[5]);
	if (argu->numofphilo < 1)
		return (-1);
	if (argu->time_to_die < 0)
		return (-1);
	if (argu->time_to_eat < 0)
		return (-1);
	if (argu->time_to_sleep < 0)
		return (-1);
	if ((argc == 6) && (argu->must_eat < 0))
		return (-1);
	return (0);
}

int	main_simul(t_argu *a, t_philo *p)
{
	if (ft_init(a, p) == -1)
	{
		ft_free(a, p);
		printf("init error\n");
		return (-1);
	}
	if (ft_simulation(a, p) == -1)
	{
		ft_free(a, p);
		printf("simulation error\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_argu	argu;
	t_philo	*philos;

	if (ar_check(argc, argv, &argu))
	{
		printf("error please check your argv!\n");
		return (0);
	}
	philos = malloc(sizeof(t_philo) * argu.numofphilo);
	argu.fork = malloc(sizeof(t_argu) * argu.numofphilo);
	if (!philos || !argu.fork)
	{
		ft_free(&argu, philos);
		printf("malloc error\n");
		return (0);
	}
	if (main_simul(&argu, philos) == -1)
		return (0);
	ft_free(&argu, philos);
	return (0);
}
