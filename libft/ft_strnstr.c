/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:07:44 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/12 11:01:22 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t cx;
	size_t dx;

	dx = 0;
	cx = 0;
	if (*little)
	{
		while (big[cx] != '\0' && cx < n)
		{
			while (little[dx] == big[cx + dx] && cx + dx < n)
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
