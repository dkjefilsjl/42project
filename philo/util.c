/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:40:01 by seoyepar          #+#    #+#             */
/*   Updated: 2022/09/01 22:45:17 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	num;

	num = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (*str != 0)
	{
		if ((!('0' <= *str && *str <= '9')))
			return (-1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

void	ft_print(t_philo *p, char *s)
{
	pthread_mutex_lock(&(p->argu->print_mtx));
	if (!ft_isfinished(p))
		printf("%lld %d %s\n", ft_gettime() - p->argu->start_time, p->id, s);
	pthread_mutex_unlock(&(p->argu->print_mtx));
}

long long	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_isfinished(t_philo *p)
{
	pthread_mutex_lock(&(p->argu->die_mtx));
	if (p->argu->finish == 1)
	{
		pthread_mutex_unlock(&(p->argu->die_mtx));
		return (1);
	}
	pthread_mutex_unlock(&(p->argu->die_mtx));
	return (0);
}

void	ft_sleep(long long start, long long time)
{
	while (time > ft_gettime() - start)
	{
		usleep(100);
	}
}
