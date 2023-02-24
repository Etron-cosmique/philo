/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:05:26 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/24 13:28:23 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac > 6 || ac < 5)
		shut_philo(&env, "Usage : ./philosopher n_philo \
tt_die tt_eat tt_sleep [n_meal]\n");
	else
		init_env(&env, ac, av);
	free(env.philo);
}
