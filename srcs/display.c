/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:04:58 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/31 02:44:05 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_sz		getsz()
{
	struct	winsize	w;
	t_sz			ws;

	ioctl(0, TIOCGWINSZ, &w);
	ws.col = w.ws_col;
	ws.row = w.ws_row;
	return (ws);
}
void	display_word(t_env env)
{
	int		x;

	x = 0;
	while (env.item->data[x] != '\0')
	{
		if (x < env.item->finded)
			ft_putstr_fd("\033[0;32m", 0);
		ft_putchar_fd(env.item->data[x], 0);
		if (x < env.item->finded)
			ft_putstr_fd("\033[0m", 0);
		x++;
	}
}
void	display_detail(t_env env, t_sz sz, int *y)
{
	tputs(tgoto(tgetstr("cm", 0), sz.col / 3, *y), 1, my_out);
	if (env.item->hover == 1)
		tputs(tgetstr("us", 0), 1, my_out);
	if (env.item->selected == 1)
		tputs(tgetstr("mr", 0), 1, my_out);
	display_word(env);
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
	if (env.max_col > sz.col / 3 + 2)
		ft_putstr_fd("resize pls", 0);
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
