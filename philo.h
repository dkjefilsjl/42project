/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyepar <seoyepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:46:41 by seoyepar          #+#    #+#             */
/*   Updated: 2022/09/02 03:28:13 by seoyepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"

typedef struct s_argu
{
	int				numofphilo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				finish;
	int				done_people;
	long long		start_time;
	pthread_t		monitor_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	done_mtx;
	pthread_mutex_t	fin_mtx;
}	t_argu;

typedef struct s_philo
{
	int				id;
	pthread_t		mine;
	pthread_mutex_t	philo_mtx;
	int				lfork;
	int				rfork;
	int				eat_cnt;
	long long		ate;
	t_argu			*argu;
}	t_philo;

int			ft_atoi(const char *str);
int			ar_check(int argc, char **argv, t_argu *argu);
int			ft_init(t_argu *argu, t_philo *philos);
int			ft_simulation(t_argu *a, t_philo *p);
void		ft_print(t_philo *p, char *s);
void		ft_sleep(long long start, long long time);
int			ft_isfinished(t_philo *p);
int			ft_eat(t_philo *p);
int			ft_nap(long long time, t_philo *p);
int			ft_think(t_philo *p);
void		ft_died(t_philo p);
void		*philo_diary(void *philo);
void		*philo_monitor(void *philos);
long long	ft_gettime(void);
int			ft_init_two(t_argu *a, t_philo *p);
int			main_simul(t_argu *a, t_philo *p);
int			philo_monitor_two(t_philo *p, int i, t_argu *a);
void		ft_free(t_argu *a, t_philo *p);

#endif
