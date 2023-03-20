/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:08:02 by clvicent          #+#    #+#             */
/*   Updated: 2023/03/20 15:48:18 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->arg->print);
	pthread_mutex_lock(&philo->last_meal.mutex);
	philo->last_meal.data = get_time();
	pthread_mutex_unlock(&philo->last_meal.mutex);
	pthread_mutex_unlock(&philo->arg->print);
	if (philo->id % 2 == 1)
		usleep(1000);
	if (philo->id % 2 == 0 && philo->id == philo->arg->n_philo - 1)
		usleep(100);
	while (!check_full(philo) && !check_death(philo, philo->arg))
	{
		if (philo->next_fork)
		{
			time_to_eat(philo);
			if (philo->n_eat != philo->arg->max_eat)
				time_to_sleep(philo);
		}
		usleep(100);
	}
	return (NULL);
}

void	time_to_eat(t_philo *philo)
{
	if (!philo->id % 2)
	{
		pthread_mutex_lock(&philo->fork);
		print("has taken a fork", philo);
		pthread_mutex_lock(philo->next_fork);
		print("has taken a fork", philo);
		get_last_eat(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
	}
	else
	{
		pthread_mutex_lock(philo->next_fork);
		print("has taken a fork", philo);
		pthread_mutex_lock(&philo->fork);
		print("has taken a fork", philo);
		get_last_eat(philo);
		pthread_mutex_unlock(philo->next_fork);
		pthread_mutex_unlock(&philo->fork);
	}
}

void	get_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal.mutex);
	philo->last_meal.data = get_time();
	pthread_mutex_unlock(&philo->last_meal.mutex);
	print("is eating", philo);
	ft_sleep(philo->arg->t_eat, philo->last_meal.data, philo);
	philo->n_eat++;
}

void	time_to_sleep(t_philo *philo)
{
	print("is sleeping", philo);
	ft_sleep(philo->arg->t_sleep, get_time(), philo);
	print("is thinking", philo);
	if (philo->arg->n_philo % 2 == 1)
		ft_sleep(((philo->arg->t_eat / 2)), get_time(), philo);
}

void	init_threads(t_env *env)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&env->arg->print);
	while (i < env->arg->n_philo)
	{
		if (i % 2)
			pthread_create(&env->philo[i].thread, NULL,
				routine, &(env->philo[i]));
		i++;
	}
	i = 0;
	while (i < env->arg->n_philo)
	{
		if (!(i % 2))
			pthread_create(&env->philo[i].thread, NULL,
				routine, &(env->philo[i]));
		i++;
	}
	pthread_mutex_unlock(&env->arg->print);
}
