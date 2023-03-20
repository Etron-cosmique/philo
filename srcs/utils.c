/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:46:29 by clvicent          #+#    #+#             */
/*   Updated: 2023/03/20 15:03:30 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	shut_philo(t_env *env, char *s)
{
	int	i;

	i = check_death(NULL, env->arg);
	if (i)
	{
		pthread_mutex_lock(&env->arg->print);
		printf("%ld %d %s", get_time() - env->arg->start, i, s);
		pthread_mutex_unlock(&env->arg->print);
	}
	else
	{
		pthread_mutex_lock(&env->arg->print);
		printf("%ld %s", get_time() - env->arg->start, s);
		pthread_mutex_unlock(&env->arg->print);
	}
	if (env->arg)
		free(env->arg);
	if (env->philo)
		free(env->philo);
	if (env)
		free(env);
	exit(0);
}

long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	print(char *s, t_philo *philo)
{
	long int	t;

	t = get_time();
	pthread_mutex_lock(&philo->arg->print);
	if (check_death(philo, philo->arg))
	{
		pthread_mutex_unlock(&philo->arg->print);
		return (0);
	}
	else
		printf("%ld %d %s\n", t - philo->arg->start, philo->id + 1, s);
	pthread_mutex_unlock(&philo->arg->print);
	return (1);
}

void	ft_sleep(long int t_wait, long int time, t_philo *philo)
{
	int	t;

	t = t_wait / 10;
	if (t > 500)
		t = 500;
	if (!t)
		t = 10;
	while (get_time() < time + t_wait && !check_death(philo, philo->arg))
		usleep(t);
}

int	death(t_philo *philo)
{
	long int	t;

	t = get_time();
	pthread_mutex_lock(&philo->arg->dead.mutex);
	if (t - philo->last_meal.data > philo->arg->t_die)
		philo->arg->dead.data = philo->id + 1;
	pthread_mutex_unlock(&philo->arg->dead.mutex);
	return (philo->arg->dead.data);
}
