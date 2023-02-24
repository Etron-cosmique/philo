/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:38:32 by clvicent          #+#    #+#             */
/*   Updated: 2021/12/13 17:45:11 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*rec;

	rec = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}		
	while (*alst && (*alst)->next != NULL)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = rec;
}
