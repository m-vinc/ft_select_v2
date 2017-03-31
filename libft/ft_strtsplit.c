/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:14:16 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/23 16:14:28 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbword(char *str)
{
	int cx;

	cx = 0;
	while (*str)
	{
		while ((*str == ' ' || *str == '\t') && *str)
			str++;
		if (*str == '\0')
			return (cx);
		while (*str != ' ' && *str != '\t' && *str)
			str++;
		if (*str == '\0')
			return (cx + 1);
		cx++;
	}
	return (cx);
}

char			**ft_strtsplit(char const *c)
{
	char	**list;
	int		x;
	int		y;
	int		wpos;

	if (!c)
		return (0);
	wpos = 0;
	x = 0;
	y = 0;
	list = (char **)malloc(sizeof(char *) * (nbword((char *)c) + 1));
	if (!list)
		return (0);
	while (wpos < nbword((char *)c) && nbword((char *)c) > 0)
	{
		while ((c[x] == ' ' || c[x] == '\t') && c[x] != '\0')
			x++;
		y = x;
		while (c[x] != ' ' && c[x] != '\t' && c[x] != '\0')
			x++;
		list[wpos] = ft_strsub((char *)c, y, x - y);
		wpos++;
	}
	list[wpos] = 0;
	return (list);
}
