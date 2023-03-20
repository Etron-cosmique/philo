/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:50:29 by clvicent          #+#    #+#             */
/*   Updated: 2023/03/20 14:52:14 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define MEM_ERR "malloc error\n"
# define MAX_EAT_ERR "max_eat must be > 0\n"
# define PARAM_ERR "params must be numeric and positive, and nbr of philo > 0\n"
# define VAL_ERR "some values are not compatible\n"
# define JOB_DONE "all meals have been eaten\n"
# define DEATH "died\n"

typedef struct s_mutex
{
	long int		data;
	pthread_mutex_t	mutex;
}	t_mutex;

typedef struct s_arg
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_eat;
	long int		start;
	pthread_mutex_t	print;
	t_mutex			dead;
}	t_arg;

typedef struct s_philo
{
	int				id;
	int				n_eat;
	pthread_t		thread;
	t_arg			*arg;
	t_mutex			last_meal;
	t_mutex			full;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
}	t_philo;

typedef struct s_env
{
	t_arg	*arg;
	t_philo	*philo;
}	t_env;

//utils
void		shut_philo(t_env *env, char *s);
long int	get_time(void);
int			print(char *s, t_philo *philo);
void		ft_sleep(long int t_wait, long int time, t_philo *philo);
int			death(t_philo *philo);

//init.c
void		set_philo(t_env *env);
void		init_philo(t_env *env);
void		set_arg(t_arg *arg, int ac, char **av);
void		init_env(t_env *env, int ac, char **av);
void		join_threads(t_env *env);

//threads_utils.c
void		*routine(void *arg);
void		time_to_eat(t_philo *philo);
void		get_last_eat(t_philo *philo);
void		time_to_sleep(t_philo *philo);
void		init_threads(t_env *env);

//checkers.c
int			check_death(t_philo *philo, t_arg *arg);
int			check_full(t_philo *philo);
int			check_all(t_env *env);
void		check_params(t_env *env, int ac);

//supervieu.c
void		superviseur(t_env *env);
int			coef(int n);

#endif