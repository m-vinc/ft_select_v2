/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystroke.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:52:51 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/31 03:46:26 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_option	*get_last(t_option *list)
{
	t_option 	*origin;
	t_option	*last;

	origin = list;
	while (list->next->data)
		list = list->next;
	last = list;
	list = origin;
	return (last);
}

void	move_cursor(int dir, t_env *env)
{
	t_option	*last;

	last = get_last((*env).item);
	//1 = en bas -> 0 en haut
	if (dir == 1)
	{
		(*env).cursor->hover = 0;
		if ((*env).cursor->next->data == 0)
			(*env).cursor = (*env).item;
		else
			(*env).cursor = (*env).cursor->next;
		(*env).cursor->hover = 1;
	}
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
	}
}

void	h_keystroke(t_env *env)
{
	char	buf[3];

	if (read(0, buf, 3) != -1)
	{
		if (buf[0] == 27)
		{
			if ((*env).search.enable != 1)
				escape(buf, env);
			else
				escape_search(buf, env);
		}
		else if (buf[0] == 127)
		{
			if ((*env).search.enable == 1)
			{
				search_backspace(env);
			}
			else
				delete_list(env);
		}
		else
			search_add(env, buf);
	}
}
