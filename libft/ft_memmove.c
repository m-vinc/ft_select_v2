/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:32:55 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/12 13:39:57 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pd;
	const char	*psrc;

	pd = dest;
	psrc = src;
	if (psrc <= pd)
	{
		psrc += n - 1;
		pd += n - 1;
		while (n--)
			*pd-- = *psrc--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
