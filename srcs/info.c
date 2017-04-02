/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 23:25:38 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/02 01:36:26 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	infomark(t_env *env)
{
	(*env).cursor->hover = 2;
}

void	build_strinfo(struct stat info, char **strinfo)
{
	showfirst(info, strinfo);
	showright(info, strinfo);
	shownumberinfo(info, strinfo);
	showtime(info, strinfo);
}

void	show_info(struct stat info, t_env *env)
{
	t_sz	sz;
	char	*strinfo;

	sz = getsz();
	strinfo = ft_strdup("\0");
	build_strinfo(info, &strinfo);
	if ((int)ft_strlen((*env).item->data) + 4 +
			(int)ft_strlen(strinfo) < sz.col)
	{
		ft_putstr_fd(" => ", 0);
		ft_putstr_fd(strinfo, 0);
	}
	else
		free(strinfo);
}

void	print_info(t_env *env)
{
	struct stat	info;
	char		*path;

	if ((*env).item->data[0] != '/')
	{
		path = ft_strdup("\0");
		path = ft_strjoinf(path, "./");
		path = ft_strjoinf(path, (*env).item->data);
	}
	else
		path = ft_strdup((*env).item->data);
	if (stat(path, &info) == -1)
	{
		free(path);
		ft_putstr_fd(" => no such file or directory", 0);
	}
	else
	{
		show_info(info, env);
	}
}
