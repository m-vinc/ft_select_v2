/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 21:30:03 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/31 22:57:59 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		select_cursor(t_env *env)
{
	if ((*env).cursor->selected == 1)
		(*env).cursor->selected = 0;
	else
		(*env).cursor->selected = 1;
	if ((*env).search.enable == 1)
		move_search_cursor(env);
	else
		move_cursor(1, env);
}
