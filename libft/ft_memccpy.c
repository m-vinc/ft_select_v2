/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:54:29 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/12 10:59:11 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			cx;

	cx = 0;
	s = (void *)src;
	d = dest;
	if (n)
	{
		while (cx < n)
		{
			if ((*d++ = (unsigned char)*s++) == (unsigned char)c)
				return (dest + cx + 1);
			cx++;
		}
	}
	return (0);
}
