/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:50:40 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/11 14:46:34 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *ptrd;
	char *ptrf;
	char *ds;
	char *sds;

	if (!s)
		return (0);
	ptrd = (char *)s;
	ptrf = ptrd + ft_strlen(s) - 1;
	while ((*ptrd == ' ' || *ptrd == '\n' || *ptrd == '\t') && *ptrd != '\0')
		ptrd++;
	if (*ptrd == '\0')
		return (ft_strdup("\0"));
	while (*ptrf == ' ' || *ptrf == '\n' || *ptrf == '\t')
		ptrf--;
	if ((ds = (char *)malloc(sizeof(char) * ((int)(ptrf - ptrd) + 2))) != 0)
	{
		sds = ds;
		while (ptrd != ptrf + 1)
			*ds++ = *ptrd++;
		*ds = '\0';
		return (sds);
	}
	return (0);
}
