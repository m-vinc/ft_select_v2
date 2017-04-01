/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:43:30 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/01 04:19:14 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env				get_max(t_env env)
{
	t_option	*origin;
	int			mrow;
	int			mcol;
	int			tmp;

	tmp = 0;
	mcol = 0;
	mrow = 0;
	origin = env.item;
	while (env.item->next && env.item->data)
	{
		mrow++;
		if ((tmp = ft_strlen(env.item->data)) > mcol)
			mcol = tmp;
		env.item = env.item->next;
	}
	env.max_row = mrow;
	env.max_col = mcol;
	env.item = origin;
	return (env);
}

t_option			*remove_option(t_option *save, char *data)
{
	t_option *onext;

	if (save->data == 0)
	{
		free(save);
		return (0);
	}
	if (save == 0)
		return (0);
	if (ft_strcmp(save->data, data) == 0)
	{
		onext = save->next;
		if (save->prev)
			save->prev->next = onext;
		if (save->next)
			save->next->prev = save->prev;
		free(save->data);
		free(save);
		if (onext)
			onext->hover = 1;
		return (onext);
	}
	save->next = remove_option(save->next, data);
	return (save);
}

t_option			*option_initializer(void)
{
	t_option *element;

	if ((element = malloc(sizeof(t_option))) == 0)
		exit(42);
	element->data = 0;
	element->selected = 0;
	element->hover = 0;
	element->finded = 0;
	element->prev = 0;
	element->next = 0;
	return (element);
}

t_option			*create_list(int ac, char **av)
{
	t_option	*head;
	t_option	*node;
	int			x;

	x = 1;
	node = option_initializer();
	head = node;
	while (x < ac)
	{
		if (x == 1)
			node->hover = 1;
		node->data = ft_strdup(av[x]);
		node->next = option_initializer();
		node->next->prev = node;
		node = node->next;
		x++;
	}
	return (head);
}

void				delete_list(t_env *env)
{
	(*env).item = remove_option((*env).item, (*env).cursor->data);
	(*env).cursor = (*env).cursor->next;
	if ((*env).cursor == 0)
		w_exit(env);
	if (!(*env).cursor->data)
	{
		(*env).cursor = (*env).item;
		if ((*env).cursor)
			(*env).cursor->hover = 1;
	}
}
