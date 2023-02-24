/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:42:50 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 16:07:16 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(str) - ft_strlen(ext);
	j = 0;
	if (i <= 0)
		return (-1);
	while (str[i] && ext[j])
	{
		if (str[i] != ext[j])
			return (-1);
		i++;
		j++;
	}
	return (1);
}

