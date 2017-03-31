/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:35:03 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/10 17:11:21 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	cx;
	size_t	len;
	char	*nstr;

	if (s && f)
	{
		cx = 0;
		len = ft_strlen(s) + 1;
		nstr = (char *)malloc(sizeof(char) * len);
		if (nstr)
		{
			while (s[cx] != '\0')
			{
				nstr[cx] = f(cx, (char)s[cx]);
				cx++;
			}
			nstr[cx] = '\0';
			return (nstr);
		}
		return (0);
	}
	return (0);
}
