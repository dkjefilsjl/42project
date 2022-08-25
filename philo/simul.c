#include "philo.h"

int	ft_simulation(t_argu *a, t_philo *p)
{
	int	i;

	i = 0;
	a->start_time = ft_gettime();
	while (i < a->numOfPhilo)
	{
		p[i].ate = a->start_time;
		if (pthread_create(&(p[i].mine), NULL, philo_diary, (void *)&p[i]) == -1)
			return (-1);
	}
	if (pthread_create(&(a->monitor_thread), NULL, philo_monitor, (void *)p) == -1)
			return (-1);
	pthread_join(a->monitor_thread, NULL);
	i = 0;
	while (i < a->numOfPhilo)
	{
		pthread_join(p[i].mine, NULL);
		i++;
	}
	return (0);
}


void	*philo_monitor(void *philos)
{
	t_philo	*p;
	int	i;

	i = 0;
	p = (t_philo *)philos;
	while (1)
	{
		if (i == p[i].argu->numOfPhilo)
			i = 0;
		pthread_mutex_lock(&(p[i].argu->done_mtx));
		if (p->argu->done_people == p[i].argu->numOfPhilo)
		{
			pthread_mutex_lock(&(p[i].argu->die_mtx));
			p->argu->finish = 1;
			pthread_mutex_unlock(&(p[i].argu->die_mtx));
			pthread_mutex_unlock(&(p[i].argu->done_mtx));
			break;
		}
		pthread_mutex_unlock(&(p[i].argu->done_mtx));
		if (ft_gettime() - p[i].ate >= p[i].argu->time_to_die)
		{
			ft_died(p[i]);
			break;
		}
		i++;
	}
	return (NULL);
}