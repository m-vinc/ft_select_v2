/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystroke_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 04:10:56 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/01 04:15:57 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	place_search_cursor(t_env *env)
{
	if ((*env).search.list->opt != 0)
	{
		(*env).cursor->hover = 0;
		(*env).cursor = (*env).search.list->opt;
		(*env).cursor->hover = 1;
	}
}
