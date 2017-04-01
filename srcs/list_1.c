/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 03:19:17 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/01 03:21:17 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_option	*get_last(t_option *list)
{
	t_option	*origin;
	t_option	*last;

	origin = list;
	while (list->next->data)
		list = list->next;
	last = list;
	list = origin;
	return (last);
}
