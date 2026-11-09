/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:42:37 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/06 18:42:49 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	neg_check(long nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

int	ft_putnbr(long n)
{
	char	res[12];
	int		i;
	long	nb;
	int		c;

	c = 0;
	nb = n;
	i = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb > 0)
	{
		res[i++] = nb % 10 + '0';
		nb /= 10;
		c++;
	}
	i--;
	while (i >= 0)
		write(1, &res[i--], 1);
	return (c + neg_check(n));
}
