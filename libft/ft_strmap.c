/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:05:57 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/10 17:08:47 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	cx;
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
				nstr[cx] = f((char)s[cx]);
				cx++;
			}
			nstr[cx] = '\0';
			return (nstr);
		}
		return (0);
	}
	return (0);
}
