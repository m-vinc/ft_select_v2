/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:53:30 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/11 10:43:18 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *n;
	char *s;

	n = malloc(sizeof(char) * size + 1);
	s = n;
	if (n)
	{
		while (size-- != 0)
			*n++ = '\0';
		*n = '\0';
		return (s);
	}
	return (0);
}
