/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:31:11 by seoyepar          #+#    #+#             */
/*   Updated: 2022/09/02 03:29:07 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_argu *a, t_philo *p)
{
	int	i;

	i = 0;
	while (i < a->numofphilo)
	{
		if (a && &(a->fork[i]))
			pthread_mutex_destroy(&(a->fork[i]));
		if ((&p[i]) && &(p[i].philo_mtx))
			pthread_mutex_destroy(&p[i].philo_mtx);
		i++;
	}
	if (a)
	{
		if (&(a->print_mtx))
			pthread_mutex_destroy(&(a->print_mtx));
		if (&(a->done_mtx))
			pthread_mutex_destroy(&(a->done_mtx));
		if (&(a->fork))
			free(a->fork);
	}
	if (p)
		free(p);
}

int	ft_init_two(t_argu *a, t_philo *p)
{
	int	i;

	i = 0;
	while (i < a->numofphilo)
	{
		if (pthread_mutex_init(&(a->fork[i]), NULL) != 0)
			return (-1);
		if (pthread_mutex_init(&(p[i].philo_mtx), NULL) != 0)
			return (-1);
		p[i].id = i + 1;
		if (i == 0)
			p[i].lfork = a->numofphilo - 1;
		else
			p[i].lfork = i - 1;
		p[i].rfork = i;
		p[i].eat_cnt = 0;
		p[i].argu = a;
		i++;
	}
	return (0);
}

int	ft_init(t_argu *a, t_philo *p)
{
	int	re;

	re = 0;
	a->finish = 0;
	a->done_people = 0;
	if (pthread_mutex_init(&(a->print_mtx), NULL) != 0 \
	|| pthread_mutex_init(&(a->done_mtx), NULL) != 0 \
	|| pthread_mutex_init(&(a->fin_mtx), NULL) != 0)
		return (-1);
	re = ft_init_two(a, p);
	return (re);
}
