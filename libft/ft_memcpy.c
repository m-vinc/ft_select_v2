/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:50:49 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/12 10:59:40 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*srcc;
	unsigned char	*destc;
	size_t			cx;

	destc = (void *)dest;
	srcc = (void *)src;
	cx = 0;
	while (cx < n)
	{
		destc[cx] = srcc[cx];
		cx++;
	}
	return (destc);
}
