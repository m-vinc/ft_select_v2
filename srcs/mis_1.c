/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:38:37 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/02 01:19:34 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			print_space(int *position)
{
	ft_putchar_fd(' ', 0);
	*position += 1;
}

static void			print_lf(int *position)
{
	ft_putchar_fd('\n', 0);
	*position = 0;
}

void				display_col(t_env env, t_sz sz, int *position)
{
	t_option	*origin;

	origin = env.item;
	tputs(tgetstr("cl", 0), 1, my_out);
	while (env.item->next && env.item->data)
	{
		if (env.item->hover >= 1)
			tputs(tgetstr("us", 0), 1, my_out);
		if (env.item->selected == 1)
			tputs(tgetstr("mr", 0), 1, my_out);
		if (*position + (int)ft_strlen(env.item->data) > sz.col)
			print_lf(position);
		ft_putstr_fd(env.item->data, 0);
		if (env.item->hover >= 1 || env.item->selected == 1)
			tputs(tgetstr("me", 0), 1, my_out);
		if (env.item->next && env.item->data)
			print_space(position);
		*position += ft_strlen(env.item->data);
		env.item = env.item->next;
	}
	env.item = origin;
	if (env.search.enable == 1)
		display_searchbar(env, sz);
}

int					get_row_usage(t_env *env, t_sz sz)
{
	int			x;
	t_option	*origin;
	int			n;
	int			res;

	x = 0;
	n = 0;
	origin = (*env).item;
	while ((*env).item->next && (*env).item->data)
	{
		x += ft_strlen((*env).item->data);
		n++;
		(*env).item = (*env).item->next;
	}
	(*env).item = origin;
	res = (x + (n - 1)) / sz.col;
	return ((res * sz.col) + ((x + (n - 1)) % sz.col));
}
