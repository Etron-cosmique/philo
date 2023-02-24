/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_putstrs_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:45:00 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:30:09 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrs_fd(char **strs, int fd)
{
	int	i;

	i = 0;
	if (!strs || fd < 0 || fd > 1024)
		return (-1);
	while (strs[i] != 0)
	{
		ft_putstr_fd(strs[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	return (i);
}
