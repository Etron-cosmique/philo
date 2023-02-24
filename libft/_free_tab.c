/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _free_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:30:18 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/16 13:58:27 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab(int **tab, int ylen)
{
	if (!tab)
		return ;
	while (--ylen >= 0)
		if (tab[ylen])
			free(tab[ylen]);
	free(tab);
	tab = NULL;
}
