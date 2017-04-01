/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 22:42:06 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/01 17:04:24 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	search_create(t_env *env)
{
	t_sopt		*node;
	t_sopt		*head;
	t_option	*save;

	if ((*env).search.list != 0)
		free_sopt(env);
	node = sopt_initializer(0);
	head = node;
	save = (*env).item;
	while ((*env).item->next && (*env).item->data)
	{
		if ((*env).item->finded > 0)
		{
			node->opt = (*env).item;
			node->next = sopt_initializer(head);
			node = node->next;
		}
		(*env).item = (*env).item->next;
	}
	(*env).item = save;
	(*env).search.list = head;
	place_search_cursor(env);
}

void	search_reset(t_env *env)
{
	t_option	*origin;

	origin = (*env).item;
	while ((*env).item->next && (*env).item->data)
	{
		(*env).item->finded = 0;
		(*env).item = (*env).item->next;
	}
	(*env).item = origin;
}

void	search_backspace(t_env *env)
{
	char	*tmp;

	if ((*env).search.str)
	{
		tmp = ft_strsub((*env).search.str, 0, ft_strlen((*env).search.str) - 1);
		free((*env).search.str);
		(*env).search.str = tmp;
		if (ft_strlen((*env).search.str) == 0)
		{
			search_reset(env);
			free((*env).search.str);
			(*env).search.str = 0;
			(*env).search.enable = 0;
		}
		else
			search_find(env);
	}
}

void	search_find(t_env *env)
{
	int			x;
	t_option	*origin;

	x = 0;
	origin = (*env).item;
	while ((*env).item->next && (*env).item->data)
	{
		while ((*env).item->data[x] != '\0' &&
				(*env).search.str[x] == (*env).item->data[x])
			x++;
		if ((*env).search.str[x] == '\0')
			(*env).item->finded = x;
		else
			(*env).item->finded = 0;
		x = 0;
		(*env).item = (*env).item->next;
	}
	(*env).item = origin;
	search_create(env);
}

void	search_add(t_env *env, char *buf)
{
	char	*carac;

	(*env).search.enable = 1;
	if (buf[0] == '\x06')
		buf[0] = 0;
	carac = ft_strsub(buf, 0, 1);
	if ((*env).search.str)
	{
		(*env).search.str = ft_strjoinf((*env).search.str, carac);
		free(carac);
	}
	else
	{
		(*env).search.str = ft_strdup("\0");
		(*env).search.str = ft_strjoinf((*env).search.str, carac);
		free(carac);
	}
	search_find(env);
}
