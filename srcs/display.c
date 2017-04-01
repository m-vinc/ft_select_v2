/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:04:58 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/01 19:11:20 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_sz	getsz(void)
{
	struct winsize	w;
	t_sz			ws;

	ioctl(0, TIOCGWINSZ, &w);
	ws.col = w.ws_col;
	ws.row = w.ws_row;
	return (ws);
}

void	display_detail(t_env env, t_sz sz, int *y)
{
	tputs(tgoto(tgetstr("cm", 0), sz.col / 3, *y), 1, my_out);
	if (env.item->hover == 1)
		tputs(tgetstr("us", 0), 1, my_out);
	if (env.item->selected == 1)
		tputs(tgetstr("mr", 0), 1, my_out);
	ft_putstr_fd(env.item->data, 0);
	if (env.item->hover == 1 || env.item->selected == 1)
		tputs(tgetstr("me", 0), 1, my_out);
	*y += 1;
}

void	display_searchbar(t_env env, t_sz sz)
{
	tputs(tgoto(tgetstr("cm", 0), 0, sz.row), 1, my_out);
	tputs(tgetstr("mr", 0), 1, my_out);
	ft_putstr_fd("Search : ", 0);
	if (env.search.str != 0)
		ft_putstr_fd(env.search.str, 0);
	tputs(tgetstr("me", 0), 1, my_out);
}

void	no_needed_row(t_sz sz, t_env *env, int *position)
{
	int		row_usage;

	if ((*env).max_col > sz.col / 3 + 2)
		ft_putendl_fd("resize pls", 0);
	else if ((*env).max_row > sz.row - 1)
	{
		row_usage = get_row_usage(env, sz);
		if (row_usage < ((sz.row - 1) * sz.col))
			display_col(*env, sz, position);
		else
			ft_putendl_fd("resize plz :(", 0);
	}
}

void	display(t_env env)
{
	t_sz		sz;
	t_option	*save;
	int			y;

	y = 0;
	if (env.item == 0)
		return ;
	save = env.item;
	sz = getsz();
	env = get_max(env);
	tputs(tgetstr("cl", 0), 1, my_out);
	if (env.max_col > sz.col / 3 + 2 || env.max_row > sz.row - 1)
		no_needed_row(sz, &env, &y);
	else
	{
		while (env.item->next && env.item->data)
		{
			display_detail(env, sz, &y);
			env.item = env.item->next;
		}
		env.item = save;
		if (env.search.enable == 1)
			display_searchbar(env, sz);
	}
}
