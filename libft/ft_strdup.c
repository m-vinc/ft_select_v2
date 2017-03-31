/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:19:39 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/10 17:13:08 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char *d;
	char *sd;

	d = malloc(sizeof(char) * ft_strlen(s) + 1);
	sd = d;
	if (d)
	{
		while (*s)
		{
			*d++ = *s++;
		}
		*d = '\0';
		return (sd);
	}
	else
	{
		return (0);
	}
}
