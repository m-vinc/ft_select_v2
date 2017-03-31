/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:18:56 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/12 12:18:01 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	cx;
	size_t	dx;

	cx = 0;
	dx = 0;
	while (dest[cx] != '\0' && cx < size)
		cx++;
	while (src[dx] != '\0' && cx + dx + 1 < size)
	{
		dest[cx + dx] = src[dx];
		dx++;
	}
	if (cx < size)
		dest[cx + dx] = '\0';
	return (cx + ft_strlen(src));
}
