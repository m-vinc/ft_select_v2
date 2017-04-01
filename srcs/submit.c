/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 03:22:21 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/01 03:37:14 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	submit(t_env *env)
{
	char		*final;
	t_option	*save;
	int			x;

	x = 0;
	final = ft_strdup("\0");
	save = (*env).item;
	while ((*env).item->next && (*env).item->data)
	{
		if ((*env).item->selected == 1)
		{
			if (x != 0)
				final = ft_strjoinf(final, " ");
			final = ft_strjoinf(final, (*env).item->data);
			if ((*env).item->next && (*env).item->data)
				x += 1;
			else
				x = 0;
		}
		(*env).item = (*env).item->next;
	}
	(*env).item = save;
	tputs(tgetstr("cl", 0), 1, my_out);
	ft_putstr_fd(final, 1);
	w_exit(env);
}
