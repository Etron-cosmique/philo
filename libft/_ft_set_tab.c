/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_set_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:49:36 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/14 17:18:14 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_tab(int xlen, int ylen, int **tab, int value)
{
	int	i;
	int	j;

	i = 0;
	while (i < ylen)
	{
		j = 0;
		while (j < xlen)
		{
			tab[i][j] = value;
			j++;
		}
		i++;
	}
}
