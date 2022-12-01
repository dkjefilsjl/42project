/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:47:27 by seoyepar          #+#    #+#             */
/*   Updated: 2022/09/02 03:28:26 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_simulation(t_argu *a, t_philo *p)
{
	int	i;

	i = 0;
	a->start_time = ft_gettime();
	while (i < a->numofphilo)
	{
		pthread_mutex_lock(&(p->philo_mtx));
		p[i].ate = a->start_time;
		pthread_mutex_unlock(&(p->philo_mtx));
		if (pthread_create(&(p[i].mine), NULL, philo_diary, (void *)&p[i]) != 0)
			return (-1);
		i++;
	}
	if (pthread_create(&(a->monitor_thread), \
	NULL, philo_monitor, (void *)p) != 0)
		return (-1);
	i = 0;
	pthread_join(a->monitor_thread, NULL);
	while (i < a->numofphilo)
	{
		pthread_join(p[i].mine, NULL);
		i++;
	}
	return (0);
}

void	*philo_monitor(void *philos)
{
	t_philo		*p;
	int			i;
	t_argu		*a;

	i = 0;
	p = (t_philo *)philos;
	a = p[0].argu;
	while (1)
	{
		if (i == a->numofphilo)
			i = 0;
		if (philo_monitor_two(p, i, a) == 1)
			break ;
		i++;
		usleep(100);
	}
	return (NULL);
}

int	philo_monitor_two(t_philo *p, int i, t_argu *a)
{
	long long	last_ate;

	pthread_mutex_lock(&(a->done_mtx));
	if (ft_isfinished(&p[i]))
		return (1);
	if (a->done_people == a->numofphilo)
	{
		pthread_mutex_lock(&(a->fin_mtx));
		p->argu->finish = 1;
		pthread_mutex_unlock(&(a->fin_mtx));
		pthread_mutex_unlock(&(a->done_mtx));
		return (1);
	}
	pthread_mutex_unlock(&(a->done_mtx));
	pthread_mutex_lock(&(p[i].philo_mtx));
	last_ate = p[i].ate;
	pthread_mutex_unlock(&(p[i].philo_mtx));
	if (ft_gettime() - last_ate >= a->time_to_die)
	{
		ft_died(p[i]);
		return (1);
	}
	return (0);
}
