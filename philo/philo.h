#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork🍴"
# define EAT "is eating🍝"
# define SLEEP "is sleeping💤"
# define THINK "is thinking🤔"
# define DIED "died😱"

typedef struct	s_argu
{
	int	numOfPhilo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int	finish;
	int	done_people;
	long long start_time;
	pthread_t monitor_thread;
	pthread_mutex_t *fork;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	done_mtx;
	pthread_mutex_t	die_mtx;
} t_argu;

typedef struct s_philo
{
	int			id;
	pthread_t	mine;
	int			lfork;
	int 		rfork;
	int			eat_cnt;
	long long 	ate;
	t_argu		*argu;
} t_philo;

int	ft_atoi(const char *str);
int		ar_check(int argc, char **argv, t_argu *argu);
int	ft_init(t_argu *argu, t_philo *philos);
int	ft_simulation(t_argu *a, t_philo *p);
void	ft_print(t_philo *p, char *s);
void	ft_sleep(long long start, long long time);
int		ft_isfinished(t_philo *p);
int		ft_eat(t_philo *p);
int		ft_nap(t_philo *p);
int		ft_think(t_philo *p);
void ft_died(t_philo p);
void	*philo_diary(void *philo);
void	*philo_monitor(void *philos);
long long ft_gettime(void);



#endif
