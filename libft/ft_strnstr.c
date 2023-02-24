/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:25:49 by clvicent          #+#    #+#             */
/*   Updated: 2021/12/08 18:27:54 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *m, const char *a, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!a[0])
		return ((char *)m);
	while (m[i] && i < l)
	{
		j = 0;
		while (m[i + j] == a[j] && (i + j) < l)
		{
			if (a[j + 1] == '\0')
				return ((char *)&m[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
