/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:40:54 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/14 14:32:40 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		while ((*alst)->next)
		{
			del((*alst)->content, (*alst)->content_size);
			(*alst) = (*alst)->next;
		}
		del((*alst)->content, (*alst)->content_size);
		free((*alst));
		(*alst) = 0;
	}
	return ;
}
