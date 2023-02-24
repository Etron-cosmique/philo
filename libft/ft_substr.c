/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:48:44 by clvicent          #+#    #+#             */
/*   Updated: 2021/12/13 17:19:18 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	checklen(const char *s, unsigned int start, size_t l)
{
	if (((int)ft_strlen(s) - (int)start) > (int)l)
		return (l);
	else
		return (ft_strlen(s) - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t l)
{
	char	*str;

	if (!s)
		return (NULL);
	if ((int)start >= (int)ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (checklen(s, start, l) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], (checklen(s, start, l) + 1));
	return (str);
}
