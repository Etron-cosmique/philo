/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:59:20 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:36:10 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printab(int **tab, int ylen, int xlen)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < ylen)
	{
		x = 0;
		while (x < xlen)
		{
			ft_putnbr_fd(tab[y][x], 1);
			ft_putchar(' ');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}
