/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:35:12 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 14:03:51 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**countwrd(const char *s, char c)
{
	int		i;
	int		j;
	char	**res;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	res = malloc(sizeof(char *) * (j + 1));
	if (!res)
		return (0);
	else
		res[j] = 0;
	return (res);
}

static int	oskour(const char *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char	*sizer(char const *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_exit(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		if (strs[i])
			free(strs[i]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	strs = countwrd(s, c);
	if (!strs)
		return (NULL);
	while (i < oskour(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		strs[i] = sizer(&s[j], c);
		if (!strs[i])
			return (ft_exit(strs));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	return (strs);
}
