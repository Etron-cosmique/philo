/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:40:28 by clvicent          #+#    #+#             */
/*   Updated: 2023/03/20 15:22:56 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, t_arg *arg)
{
	if (philo)
		death(philo);
	pthread_mutex_lock(&arg->dead.mutex);
	if (arg->dead.data >= 0)
	{
		pthread_mutex_unlock(&arg->dead.mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&arg->dead.mutex);
		return (0);
	}
}

int	check_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->full.mutex);
	if (philo->n_eat == philo->arg->max_eat && philo->full.data != 1)
		philo->full.data = 1;
	pthread_mutex_unlock(&philo->full.mutex);
	return ((int)philo->full.data);
}

int	check_all(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->arg->n_philo)
	{
		if (!check_full(&env->philo[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_params(t_env *env, int ac)
{
	if (ac == 6 && env->arg->max_eat <= 0)
		shut_philo(env, MAX_EAT_ERR);
	if (env->arg->n_philo <= 0 || env->arg->t_die < 0 || env->arg->t_eat < 0
		|| env->arg->t_sleep < 0)
		shut_philo(env, PARAM_ERR);
}
