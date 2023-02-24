/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:03:56 by clvicent          #+#    #+#             */
/*   Updated: 2021/12/08 18:22:29 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	b;

	b = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == b)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == b)
		return (((char *)&s[i]));
	return (NULL);
}
