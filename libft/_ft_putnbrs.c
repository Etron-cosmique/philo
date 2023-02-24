/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_putnbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:59:26 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:33:33 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int n, char *b)
{
	unsigned int	s;
	int				i;

	s = (unsigned int)ft_strlen(b);
	i = 0;
	if (n >= s)
	{
		ft_putnbr_base((n / s), b);
		ft_putchar(b[n % s]);
		i++;
	}
	else
	{
		ft_putchar(b[n % s]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int i)
{
	unsigned int	n;
	int				c;

	c = 0;
	if (i < 0)
	{
		n = -i;
		ft_putchar('-');
		c++;
	}
	else
		n = i;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
		c++;
	}
	else
		ft_putchar(n + 48);
	c++;
	return (c);
}

int	ft_putnbru(unsigned int i)
{
	int				c;

	c = 0;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10);
		c++;
	}
	else
		ft_putchar(i);
	c++;
	return (c);
}
