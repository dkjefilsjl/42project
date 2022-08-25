#include "philo.h"

int	ar_check(int argc, char **argv, t_argu *argu)
{
	int	check;

	check = 0;
	if ((argc != 5) && (argc != 6))
		return (0);
	argu->numOfPhilo= ft_atoi(argv[1]);
	argu->time_to_die = ft_atoi(argv[2]);
	argu->time_to_eat = ft_atoi(argv[3]);
	argu->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		argu->must_eat = ft_atoi(argv[5]);
	if (argu->numOfPhilo < 1)
		return -1;
	if (argu->time_to_die < 0)
		return -1;
	if (argu->time_to_eat < 0)
		return -1;
	if (argu->time_to_sleep < 0)
		return -1;
	if ((argc == 6) && (argu->must_eat < 0))
		return -1;
	return (0);
}

int	ft_init(t_argu *argu, t_philo *philos)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(argu->print_mtx), NULL) != 0 \
	 || pthread_mutex_init(&(argu->done_mtx), NULL) != 0 \
	 || pthread_mutex_init(&(argu->die_mtx), NULL) != 0)
			return (-1);
	while(i < argu->numOfPhilo)
	{
		if (pthread_mutex_init(&(argu->fork[i]), NULL) != 0)
			return (-1);
		philos[i].id = i + 1;
		if (i == 0)
			philos[i].lfork = argu->numOfPhilo - 1;
		else
			philos[i].lfork = i - 1;
		philos[i].rfork = i;
		philos[i].eat_cnt = 0;
		philos[i].argu = argu;
		i++;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_argu	argu;
	t_philo *philos;

	if (ar_check(argc, argv, &argu))
	{
		printf("error please check your hand!\n");
		return (0);
	}
	philos = malloc(sizeof(t_philo) * argu.numOfPhilo);
	argu.fork = malloc(sizeof(t_argu) * argu.numOfPhilo);
	if (!philos || !argu.fork)
	{
		printf("malloc error\n");
		return(0);
	}
	if (ft_init(&argu, philos) == -1)
	{
		printf("init error\n");
		return (0);
	}
	if (ft_simulation(&argu, philos) == -1)
	{
		printf("simulation error\n");
		return (0);
	}
}