/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystroke.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:52:51 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/02 01:06:41 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		move_search_cursor(t_env *env)
{
	if ((*env).search.list->opt)
	{
		(*env).cursor->hover = 0;
		if ((*env).search.list->next->opt == 0)
		{
			if ((*env).search.list->origin != 0)
			{
				(*env).search.list = (*env).search.list->origin;
				(*env).cursor = (*env).search.list->opt;
			}
		}
		else
		{
			(*env).cursor = (*env).search.list->next->opt;
			(*env).search.list = (*env).search.list->next;
		}
		(*env).cursor->hover = 1;
	}
}

void		move_cursor(int dir, t_env *env)
{
	t_option	*last;

	last = get_last((*env).item);
	if (dir == 1)
	{
		(*env).cursor->hover = 0;
		if ((*env).cursor->next->data == 0)
			(*env).cursor = (*env).item;
		else
			(*env).cursor = (*env).cursor->next;
		(*env).cursor->hover = 1;
	}
	else if (dir == 2)
		move_search_cursor(env);
	else
	{
		(*env).cursor->hover = 0;
		if ((*env).cursor->prev == 0)
			(*env).cursor = last;
		else
			(*env).cursor = (*env).cursor->prev;
		(*env).cursor->hover = 1;
	}
}

void		escape_search(char *buf, t_env *env)
{
	if (buf[2] == 'C')
		move_cursor(2, env);
	if (buf[2] == 'B')
		move_cursor(2, env);
	if (buf[2] == 0)
	{
		if ((*env).search.enable == 1)
		{
			(*env).search.enable = 0;
			if ((*env).search.str)
			{
				free((*env).search.str);
				search_reset(env);
				(*env).search.str = 0;
			}
		}
	}
}

void		escape(char *buf, t_env *env)
{
	if (buf[2] == 'C')
		move_cursor(1, env);
	else if (buf[2] == 'D')
		move_cursor(0, env);
	else if (buf[2] == 'B')
		move_cursor(1, env);
	else if (buf[2] == 'A')
		move_cursor(0, env);
	else if (buf[2] == 0)
	{
		if ((*env).search.enable == 1)
		{
			(*env).search.enable = 0;
			if ((*env).search.str)
			{
				free((*env).search.str);
				(*env).search.str = 0;
			}
		}
		else
			w_exit(env);
	}
}

void		h_keystroke(t_env *env)
{
	char	buf[3];

	if (read(0, buf, 3) != -1)
	{
		if (buf[0] == 27)
			if ((*env).search.enable != 1)
				escape(buf, env);
			else
				escape_search(buf, env);
		else if (buf[0] == 127)
			if ((*env).search.enable == 1)
				search_backspace(env);
			else
				delete_list(env);
		else if (((buf[0] == ' ' && (*env).search.enable == 0)) ||
				(buf[0] == 24))
			select_cursor(env);
		else if (buf[0] == 10 && (*env).search.enable == 0)
			submit(env);
		else if (ft_isprint(buf[0]) || buf[0] == 6)
			search_add(env, buf);
		else if (buf[0] == '\x05')
			infomark(env);
	}
}
