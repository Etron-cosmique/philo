/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:26:01 by clvicent          #+#    #+#             */
/*   Updated: 2023/03/20 15:18:09 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->arg->n_philo)
	{
		env->philo[i].id = i;
		env->philo[i].n_eat = 0;
		pthread_mutex_init(&env->philo[i].fork, NULL);
		pthread_mutex_init(&env->philo[i].full.mutex, NULL);
		pthread_mutex_init(&env->philo[i].last_meal.mutex, NULL);
		env->philo[i].full.data = 0;
		env->philo[i].last_meal.data = 0;
		env->philo[i].arg = env->arg;
		i++;
	}
}

void	init_philo(t_env *env)
{
	int	i;

	i = 0;
	set_philo(env);
	while (i < env->arg->n_philo)
	{
		if (env->arg->n_philo == 1)
			env->philo[i].next_fork = NULL;
		else if (i + 1 == env->arg->n_philo)
			env->philo[i].next_fork = &env->philo[0].fork;
		else
			env->philo[i].next_fork = &env->philo[i + 1].fork;
		i++;
	}
	init_threads(env);
	join_threads(env);
	superviseur(env);
}

void	set_arg(t_arg *arg, int ac, char **av)
{
	arg->n_philo = ft_atoi(av[1]);
	arg->t_die = ft_atoi(av[2]);
	arg->t_eat = ft_atoi(av[3]);
	arg->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		arg->max_eat = ft_atoi(av[5]);
	else
		arg->max_eat = -1;
	arg->start = get_time();
	pthread_mutex_init(&arg->print, NULL);
	pthread_mutex_init(&arg->dead.mutex, NULL);
	arg->dead.data = -1;
}

void	init_env(t_env *env, int ac, char **av)
{
	env = malloc(sizeof(t_env));
	if (!env)
		shut_philo(env, MEM_ERR);
	env->arg = malloc(sizeof(t_arg));
	if (!env->arg)
		shut_philo(env, MEM_ERR);
	set_arg(env->arg, ac, av);
	check_params(env, ac);
	env->philo = malloc(sizeof(t_philo) * env->arg->n_philo);
	if (!env->philo)
		shut_philo(env, MEM_ERR);
	init_philo(env);
}

void	join_threads(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->arg->n_philo)
	{
		pthread_join(env->philo[i].thread, NULL);
		i++;
	}
}
