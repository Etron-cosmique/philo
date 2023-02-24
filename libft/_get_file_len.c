/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_file_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:59:08 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/17 09:57:14 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_file_len(char *filename)
{
	int		fd;
	int		len;
	char	*str;

	str = NULL;
	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0 || fd > 1024)
	{
		ft_putstr_fd("Wrong fd\n", 1);
		return (fd);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		len++;
	}
	if (str)
		free(str);
	return (len);
}
