/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:50:29 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/24 14:39:15 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef	struct s_mutex
{
	int				flag;
	pthread_mutex_t mutex;
}	t_mutex;

typedef struct s_data
{
	int		id;
	int		n_eat;
	t_mutex	fork;
	t_mutex *next_fork;
	int		dead
}	t_data;

typedef struct s_env
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_eat;
	t_data	*philo;
}	t_env;

void	shut_philo(t_env *env, char *s);
void	init_env(t_env *env, int ac, char **av);

#endif