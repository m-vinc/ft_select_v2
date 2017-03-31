/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:53:50 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/31 05:11:32 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_sopt(t_env *env)
{
	t_sopt	*tmp;

	while ((*env).search.list)
	{
		tmp = (*env).search.list;
		(*env).search.list = (*env).search.list->next;
		free(tmp);
	}
}
t_sopt	*sopt_initializer(t_sopt *origin)
{
	t_sopt	*new;

	if ((new = malloc(sizeof(t_sopt))) == 0)
		exit(42);
	new->opt = 0;
	new->origin = (origin == 0 ? 0 : origin);
	new->next = 0;
	return (new);
}

int		my_out(int c)
{
	return (write(0, &c, 1));
}
char	*ft_strjoinf(char *one, char *two)
{
	char *tmp;

	tmp = ft_strjoin(one, two);
	free(one);
	return (tmp);
}

void	w_exit(t_env *env)
{
	t_option	*save;

	tputs(tgetstr("ve", 0), 1, my_out);
	tcsetattr(0, TCSADRAIN, &(*env).default_settings);
	while ((*env).item)
	{
		if ((*env).item->data)
			free((*env).item->data);
		save = (*env).item;
		(*env).item = (*env).item->next;
		free(save);
	}
	if ((*env).search.str)
		free((*env).search.str);
	exit(0);	
}
