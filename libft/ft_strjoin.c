/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:20:15 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/10 17:13:26 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *f;

	if (s1 && s2)
	{
		f = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (f)
		{
			f = ft_strcat(f, s1);
			f = ft_strcat(f, s2);
			return (f);
		}
		return (0);
	}
	return (0);
}
