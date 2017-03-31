/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:59:50 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/10 10:04:14 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int cx;
	int dx;

	dx = 0;
	cx = 0;
	if (*little)
	{
		while (big[cx] != '\0')
		{
			while (little[dx] == big[cx + dx])
			{
				if (little[dx + 1] == '\0')
					return ((char *)big + cx);
				dx++;
			}
			dx = 0;
			cx++;
		}
		return (0);
	}
	return ((char *)big);
}
