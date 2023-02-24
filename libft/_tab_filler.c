/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tab_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:37:45 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/14 17:53:54 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tab_filler(int **tab, char **data, int index)
{
	int	i;

	i = 0;
	while (data[i])
	{
		tab[index][i] = ft_atoi(data[i]);
		i++;
	}
}
