/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:55:15 by vmorvan           #+#    #+#             */
/*   Updated: 2016/11/14 15:52:11 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	r;

	if (n == 0)
		return (1);
	if (s1 && s2 && n)
	{
		r = ft_strncmp(s1, s2, n);
		if (r == 0)
			return (1);
		return (0);
	}
	return (0);
}
