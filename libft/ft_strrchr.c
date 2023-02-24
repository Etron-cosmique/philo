/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:32:23 by clvicent          #+#    #+#             */
/*   Updated: 2021/12/08 18:25:00 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	int		i;
	char	b;

	b = (char)c;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == b)
			j = i;
		i++;
	}
	if (s[i] == b)
		return ((char *)&s[i]);
	if (j >= 0)
		return ((char *)&s[j]);
	return (NULL);
}
