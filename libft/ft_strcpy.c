/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:43:25 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/11 10:31:49 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int cx;

	cx = 0;
	while (src[cx] != '\0')
	{
		dst[cx] = src[cx];
		cx++;
	}
	dst[cx] = '\0';
	return (dst);
}
