/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_print_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:25:04 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:35:56 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printp(unsigned long long n, char *b)
{
	unsigned long long	s;
	int					i;

	s = (unsigned long long)ft_strlen(b);
	i = 0;
	if (n >= s)
	{
		ft_printp((n / s), b);
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

int	ft_print_ptr(void *p)
{
	if (!p)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	return (2 + ft_printp((unsigned long long)p, "0123456789abcdef"));
}
