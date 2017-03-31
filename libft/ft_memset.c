/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:47:35 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/12 10:59:58 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			cx;
	unsigned char	*ss;

	ss = s;
	cx = 0;
	while (cx < n)
	{
		ss[cx] = (unsigned char)c;
		cx++;
	}
	return (ss);
}
