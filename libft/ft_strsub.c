/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:57:44 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/11 14:48:09 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *o;

	if (!s)
		return (0);
	o = ft_memalloc(len + 1);
	if (o)
		ft_strncpy(o, (s + start), len);
	return (o);
}
