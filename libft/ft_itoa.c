/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:43:20 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/07 23:03:12 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				cbdigit(int n)
{
	int c;

	c = 0;
	if (n < 0)
	{
		c++;
		n *= -1;
	}
	while (n != 0)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static char		*w_zdup(char *ito)
{
	free(ito);
	return (ft_strdup("0"));
}

char			*ft_itoa(int n)
{
	int		digit;
	char	*ito;
	int		cx;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = cbdigit(n);
	cx = digit - 1;
	if ((ito = (char *)malloc(sizeof(char) * (digit + 1))) == 0)
		return (0);
	if (n == 0)
		return (w_zdup(ito));
	ito[digit] = 0;
	if (n < 0)
	{
		ito[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		ito[cx] = ((n % 10) + '0');
		cx--;
		n /= 10;
	}
	return (ito);
}
