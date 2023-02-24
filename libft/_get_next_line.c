/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:04:47 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/17 11:47:46 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*ft_pull(char *stc)
// {
// 	char	*line;

// 	if (get_index(stc) == -1)
// 		line = ft_substr(stc, 0, ft_strlen(stc));
// 	else
// 		line = ft_substr(stc, 0, get_index(stc) + 1);
// 	return (line);
// }

// static char	*ft_clear_static(char *stc)
// {
// 	char	*new_stc;

// 	if (get_index(stc) == -1)
// 	{
// 		free(stc);
// 		stc = NULL;
// 		return (NULL);
// 	}
// 	new_stc = ft_strdup(&stc[get_index(stc) + 1]);
// 	free(stc);
// 	return (new_stc);
// }

// static char	*ft_free(char *stc, char *buf, int i)
// {
// 	if (i == 1)
// 	{
// 		free(buf);
// 		free(stc);
// 		return (NULL);
// 	}
// 	else
// 	{
// 		free(buf);
// 		return (stc);
// 	}
// }

// static char	*ft_read(int fd, char *stc)
// {
// 	int		i;
// 	char	*buf;
// 	char	*tmp;

// 	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (!buf)
// 		return (NULL);
// 	i = 1;
// 	while (i > 0 && get_index(stc) == -1)
// 	{
// 		i = read(fd, buf, BUFFER_SIZE);
// 		if ((i == -1 || i == 0) && !stc[0])
// 			return (ft_free(stc, buf, 1));
// 		if (i > 0)
// 			buf[i] = '\0';
// 		if (i == 0 && stc[0])
// 			return (ft_free(stc, buf, 0));
// 		tmp = stc;
// 		stc = ft_strjoin(stc, buf);
// 	}
// 	if (tmp)
// 		free(tmp);
// 	free(buf);
// 	return (stc);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*stc;

// 	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
// 		return (NULL);
// 	if (!stc)
// 	{
// 		stc = malloc(1);
// 		if (!stc)
// 			return (NULL);
// 		stc[0] = '\0';
// 	}
// 	if (get_index(stc) == -1)
// 	{
// 		stc = ft_read(fd, stc);
// 		if (!stc)
// 			return (NULL);
// 	}
// 	line = ft_pull(stc);
// 	stc = ft_clear_static(stc);
// 	return (line);
// }
static int	ft_read(int fd, char **buf, char **stc)
{
	int		i;
	char	*str;

	i = 1;
	while (i && !ft_strchr(*stc, '\n'))
	{
		i = read(fd, *buf, BUFFER_SIZE);
		if (i == -1)
			return (-1);
		(*buf)[i] = 0;
		str = *stc;
		*stc = ft_strjoin(str, *buf);
		free(str);
		str = NULL;
	}
	return (i);
}

static char	*ft_pull(char **stc)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while ((*stc)[i] && (*stc)[i] != '\n')
		i++;
	tmp = *stc;
	*stc = ft_strdup(&(*stc)[i + 1]);
	line = ft_substr(tmp, 0, i + 1);
	free(tmp);
	tmp = NULL;
	return (line);
}

static char	*ft_line(int fd, char **buf, char **stc)
{
	int		i;
	char	*tmp;

	if (ft_strchr(*stc, '\n'))
		return (ft_pull(stc));
	i = ft_read(fd, buf, stc);
	if ((i == -1 || i == 0) && !**stc)
	{
		free(*stc);
		*stc = NULL;
		return (NULL);
	}
	if (ft_strchr(*stc, '\n'))
		return (ft_pull(stc));
	if (**stc)
	{
		tmp = ft_strdup(*stc);
		free(*stc);
		*stc = NULL;
		return (tmp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stc[1025];
	char		*line;
	char		*buf;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!stc[fd])
		stc[fd] = ft_strdup("");
	if (!stc[fd])
		return (NULL);
	line = ft_line(fd, &buf, &stc[fd]);
	free(buf);
	buf = NULL;
	return (line);
}
