#include "philo.h"

int		ft_eat(t_philo *p)
{
	pthread_mutex_lock(&(p->argu->fork[p->lfork]));
	if(!ft_isfinished(p))
		ft_print(p, FORK);
	if (p->argu->numOfPhilo == 1)
	{
		ft_sleep(p->ate, p->argu->time_to_die);
		return (1);
	}
	pthread_mutex_lock(&(p->argu->fork[p->rfork]));
	if (!ft_isfinished(p))
		ft_print(p, FORK);
	p->ate = ft_gettime();
	if (!ft_isfinished(p))
		ft_print(p, EAT);
	ft_sleep(p->ate, p->argu->time_to_eat);
	p->eat_cnt++;
	pthread_mutex_lock(&(p->argu->done_mtx));
	if (p->eat_cnt == p->argu->must_eat)
		p->argu->done_people++;
	pthread_mutex_unlock(&(p->argu->done_mtx));
	pthread_mutex_unlock(&(p->argu->fork[p->lfork]));
	pthread_mutex_unlock(&(p->argu->fork[p->rfork]));
	return (0);
}

int		ft_nap(t_philo *p)
{
	if (!ft_isfinished(p))
	{
		ft_print(p, SLEEP);
		ft_sleep(ft_gettime(), p->argu->time_to_sleep);
	}
	else
		return (1);
	return (0);
}

int		ft_think(t_philo *p)
{
	if (!ft_isfinished(p))
		ft_print(p, THINK);
	else
		return (1);
	return (0);
}

void ft_died(t_philo p)
{
	pthread_mutex_lock(&(p.argu->die_mtx));
	pthread_mutex_lock(&(p.argu->print_mtx));
	p.argu->finish = 1;
	printf("%lld %d %s\n", ft_gettime() - p.argu->start_time, p.id, DIED);
	pthread_mutex_unlock(&(p.argu->die_mtx));
	pthread_mutex_unlock(&(p.argu->print_mtx));
}

void	*philo_diary(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if ((p->id % 2) == 0)
		usleep(100);
	while (1)
	{
		if (ft_eat(p) || ft_nap(p) || ft_think(p))
			break;
		usleep(100);
	}
	return (NULL);
}