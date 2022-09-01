#include "philo.h"

int	ft_simulation(t_argu *a, t_philo *p)
{
	int	i;

	i = 0;
	a->start_time = ft_gettime();
	while (i < a->numOfPhilo)
	{
		p[i].ate = a->start_time;
		if (pthread_create(&(p[i].mine), NULL, philo_diary, (void *)&p[i]) != 0)
			return (-1);
		i++;
	}
	if (pthread_create(&(a->monitor_thread), NULL, philo_monitor, (void *)p) != 0)
			return (-1);
	i = 0;
	pthread_join(a->monitor_thread, NULL);
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
	t_argu *a;

	i = 0;
	p = (t_philo *)philos;
	a =  p[0].argu;
	//printf("monitor\n");
	while (1)
	{
		//printf("monitor\n");
		if (i == a->numOfPhilo)
			i = 0;
		pthread_mutex_lock(&(a->done_mtx));
		if (ft_isfinished(&p[i]))
			break;
		if (a->done_people == a->numOfPhilo)
		{
			pthread_mutex_lock(&(a->die_mtx));
			p->argu->finish = 1;
			pthread_mutex_unlock(&(a->die_mtx));
			pthread_mutex_unlock(&(a->done_mtx));
			break;
		}
		pthread_mutex_unlock(&(a->done_mtx));
		//pthread_mutex_lock(&(p[i].philo_mtx));
		if (ft_gettime()- p[i].ate >= a->time_to_die)
		{
			//pthread_mutex_unlock(&(p[i].philo_mtx));
			ft_died(p[i]);
			break;
		}
		i++;
		usleep(100);
	}
	return (NULL);
}