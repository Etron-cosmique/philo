/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:55:12 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:32:35 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'u')
		return (ft_putnbru(va_arg(list, int)));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF"));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789abdef"));
	if (c == 'p')
		return (ft_print_ptr(va_arg(list, void *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	params;

	va_start (params, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		write (1, &s[i], ft_get_char(&s[i], '%'));
		count += ft_get_char(&s[i], '%');
		i += ft_get_char(&s[i], '%');
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			count += ft_convert(s[i], params);
			i++;
		}
	}
	va_end(params);
	return (count);
}
