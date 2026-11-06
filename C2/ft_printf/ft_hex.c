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

static void upper(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'f')
			*s = *s - 32;
		s++;
	}
}

int put_hex(long nb, int cs)
{
	int i;
	char hex[17] = "0123456789abcdef";
	char c[17];

	i = 0;
	if (cs)
		upper(hex);
	while (nb > 0)
	{
		c[i] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	putstr(c);
	return (i);
}

int put_addr(void *p)
{
	unsigned long	nb;
	int				i;
	
	write(1, "0x", 2);
	nb = (unsigned long)p;
	i = put_hex(nb, 0);
	//printf("\n%ld", nb);
	return (i);
}
