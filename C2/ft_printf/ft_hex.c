/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:43:02 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/06 18:43:09 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(long nb, int cs)
{
	int		i;
	char	*hex;
	char	c[17];

	i = 0;
	if (cs)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb == 0)
		return (ft_putchar('0'), 1);
	while (nb > 0)
	{
		c[i] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	c[i] = '\0';
	rev_putstr(c);
	return (i);
}

int	put_addr(void *p)
{
	unsigned long	nb;
	int				i;

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	nb = (unsigned long)p;
	i = put_hex(nb, 0);
	return (i + 2);
}
