/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:51:24 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/14 11:55:38 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbword(char *str, char ch)
{
	int cx;

	cx = 0;
	while (*str)
	{
		while (*str == ch && *str)
			str++;
		if (*str == '\0')
			return (cx);
		while (*str != ch && *str)
			str++;
		if (*str == '\0')
			return (cx + 1);
		cx++;
	}
	return (cx);
}

char			**ft_strsplit(char const *c, char ch)
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
	list = (char **)malloc(sizeof(char *) * (nbword((char *)c, ch) + 1));
	if (!list)
		return (0);
	while (wpos < nbword((char *)c, ch) && nbword((char *)c, ch) > 0)
	{
		while (c[x] == ch && c[x] != '\0')
			x++;
		y = x;
		while (c[x] != ch && c[x] != '\0')
			x++;
		list[wpos] = ft_strsub((char *)c, y, x - y);
		wpos++;
	}
	list[wpos] = 0;
	return (list);
}
