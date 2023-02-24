/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:44:18 by clvicent          #+#    #+#             */
/*   Updated: 2021/12/02 14:49:07 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc(int n)
{
	unsigned int	nb;
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	else
		nb = n;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				i;
	char			*tab;

	i = alloc(n);
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = '\0';
	if (n == 0)
		tab[--i] = '0';
	if (n < 0)
	{
		nb = -n;
		tab[0] = '-';
	}
	else
		nb = n;
	while (nb != 0)
	{
		tab[--i] = ((nb % 10) + '0');
		nb /= 10;
	}
	return (tab);
}
