/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:48:18 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/06 17:48:20 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatcher(va_list v, char c)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(v, int)));
	if (c == 's')
		return (ft_putstr(va_arg(v, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(v, int)));
	if (c == 'x')
		return (put_hex(va_arg(v, unsigned int), 0));
	if (c == 'X')
		return (put_hex(va_arg(v, unsigned int), 1));
	if (c == 'p')
		return (put_addr(va_arg(v, void *)));
	if (c == 'u')
		return (ft_putnbr(va_arg(v, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	v;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!format || write(1, "", 0) == -1)
		return (-1);
	va_start(v, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_memchr("cspdiuxX%", format[i + 1], 9))
		{
			count += dispatcher(v, ft_memchr("cspdiuxX%", format[i + 1], 9));
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(v);
	return ((int)count);
}
