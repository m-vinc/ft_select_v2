/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:14:48 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/10 13:28:27 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int cx;
	int dx;

	dx = 0;
	cx = 0;
	while (dest[cx] != '\0')
		cx++;
	while (src[dx] != '\0' && n-- != 0)
	{
		dest[cx] = src[dx];
		cx++;
		dx++;
	}
	dest[cx] = '\0';
	return (dest);
}
