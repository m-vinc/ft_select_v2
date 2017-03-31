/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:15:29 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/12 13:46:48 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*s;

	s = dest;
	while (n > 0)
	{
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = 0;
		n--;
	}
	return (s);
}
