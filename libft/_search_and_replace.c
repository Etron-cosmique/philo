/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _search_and_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:54 by clvicent          #+#    #+#             */
/*   Updated: 2023/03/09 16:34:31 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *s_and_r(char *str, char s, char r)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == s)
			str[i] = r;
		i++;
	}
	return (str);
}
