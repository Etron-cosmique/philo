/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviseur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:48:07 by clvicent          #+#    #+#             */
/*   Updated: 2023/03/20 15:23:54 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	superviseur(t_env *env)
{
	while (1)
	{
		if (env->arg->max_eat != -1)
			if (check_all(env))
				shut_philo(env, JOB_DONE);
		if (check_death(NULL, env->arg))
			shut_philo(env, DEATH);
		usleep(100);
	}
}

int	coef(int n)
{
	if (n < 10)
		return (1);
	else if (n > 9 && n < 101)
		return (n / 10);
	return (10);
}
