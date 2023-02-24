/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:32:29 by clvicent          #+#    #+#             */
/*   Updated: 2021/12/08 16:03:57 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(dst);
	if (size == 0 || l >= size)
		return (size + ft_strlen((char *)src));
	while (src[i] && (i + l < size - 1))
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = 0;
	return (l + ft_strlen((char *)src));
}
