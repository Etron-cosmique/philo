/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:46:29 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/24 15:01:59 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	shut_philo(t_env *env, char *s)
{
	printf("%s"	, s);
	if (env->philo)
		free(env->philo);
	exit(0);
}

void	init_env(t_env *env, int ac, char **av)
{
	if (ac == 6)
		env->n_eat = ft_atoi(av[5]);
	else
		env->n_eat = -1;
	env->n_philo = ft_atoi(av[1]);
	env->t_die = ft_atoi(av[2]);
	env->t_eat = ft_atoi(av[3]);
	env->t_sleep = ft_atoi(av[4]);
	if (env->n_philo <= 0 || env->t_die < 0 || env->t_eat < 0
		|| env->t_sleep < 0)
		shut_philo(env, "bad arguments\n");
	env->philo = malloc(sizeof(t_data) * env->n_philo);
	if (!env->philo)
		shut_philo(env, "malloc error\n");
}

long int		get_time(void)
{
	struct	timeval	tv;
	
	if (!gettimeofday(&tv, NULL))
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	init_philo(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_philo)
	{
		set_params(env->philo[i]);
		if (env->n_philo == 1)
			env->philo[i].next_fork = NULL;
		else if (i + 1 == env->n_philo)
			env->philo[i].next_fork = &env->philo[0].fork;
		else
			env->philo[i].next_fork = &env->philo[i + 1].fork;
		i++;
	}
}
