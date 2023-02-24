/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_gen_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:28:04 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:01:41 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_gen_tab(int xlen, int ylen, int value)
{
	int	i;
	int	**tab;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * ylen);
	if (!tab)
		return (NULL);
	while (i < ylen)
	{
		tab[i] = (int *)malloc(sizeof(int) * xlen);
		if (!tab[i])
		{
			while (i >= 0)
			{
				free(tab[i]);
				i--;
			}
			free(tab);
		}
		i++;
	}
	if (tab)
		ft_set_tab(xlen, ylen, tab, value);
	return (tab);
}
