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

int	dispatcher(va_list v, char c) 
{
	int	count;

	count = 0;
	if (c == 'c')
	{
		ft_putchar((char)va_arg(v, int));
		count++;
	}
	if (c == 's')
		count = ft_putstr(va_arg(v, char *));
	if (c == 'i' || c == 'd')
		count = ft_putnbr(va_arg(v, int));
	if (c == 'x')
		count = put_hex((long)va_arg(v, unsigned int), 0);
	if (c == 'X')
		count = put_hex((long)va_arg(v, unsigned int), 1);
	if (c == 'p')
		count = put_addr(va_arg(v, void *));
	if (c == 'u')
		count = ft_putunsinged(va_arg(v, unsigned int));
	if (c == '%')
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	v;
	int		i;
	int	count;

	count = 0;
	i = 0;
	if (!format)
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
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(v);
	return ((int)count);
}
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int		r1;
	int		r2;
	char	*null_str;
	void	*null_ptr;
	int		x;

	null_str = NULL;
	null_ptr = NULL;
	x = 42;

	/* %c */
	r1 = printf("[c] real: %c|\n", 'A');
	r2 = ft_printf("[c] mine: %c|\n", 'A');
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %s */
	r1 = printf("[s] real: %s|\n", "hello");
	r2 = ft_printf("[s] mine: %s|\n", "hello");
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %s empty string */
	r1 = printf("[s empty] real: %s|\n", "");
	r2 = ft_printf("[s empty] mine: %s|\n", "");
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %s NULL */
	r1 = printf("[s NULL] real: %s|\n", null_str);
	r2 = ft_printf("[s NULL] mine: %s|\n", null_str);
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %d and %i */
	r1 = printf("[d] real: %d %d %d|\n", 0, 7, -7);
	r2 = ft_printf("[d] mine: %d %d %d|\n", 0, 7, -7);
	printf("returns: %d vs %d\n\n", r1, r2);

	r1 = printf("[i] real: %i %i|\n", 123, -123);
	r2 = ft_printf("[i] mine: %i %i|\n", 123, -123);
	printf("returns: %d vs %d\n\n", r1, r2);

	/* limits */
	r1 = printf("[limits] real: %d %d|\n", INT_MAX, INT_MIN);
	r2 = ft_printf("[limits] mine: %d %d|\n", INT_MAX, INT_MIN);
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %u */
	r1 = printf("[u] real: %u %u %u|\n", 0, 42, UINT_MAX);
	r2 = ft_printf("[u] mine: %u %u %u|\n", 0, 42, UINT_MAX);
	printf("returns: %d vs %d\n\n", r1, r2);

	r1 = printf("[u neg] real: %u|\n", -1);
	r2 = ft_printf("[u neg] mine: %u|\n", -1);
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %x and %X */
	r1 = printf("[x] real: %x %x %x|\n", 0, 255, 4096);
	r2 = ft_printf("[x] mine: %x %x %x|\n", 0, 255, 4096);
	printf("returns: %d vs %d\n\n", r1, r2);

	r1 = printf("[X] real: %X %X|\n", 255, 48879);
	r2 = ft_printf("[X] mine: %X %X|\n", 255, 48879);
	printf("returns: %d vs %d\n\n", r1, r2);

	r1 = printf("[x neg] real: %x %X|\n", -1, -1);
	r2 = ft_printf("[x neg] mine: %x %X|\n", -1, -1);
	printf("returns: %d vs %d\n\n", r1, r2);

	r1 = printf("[x max] real: %x|\n", UINT_MAX);
	r2 = ft_printf("[x max] mine: %x|\n", UINT_MAX);
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %p */
	r1 = printf("[p] real: %p|\n", &x);
	r2 = ft_printf("[p] mine: %p|\n", &x);
	printf("returns: %d vs %d\n\n", r1, r2);

	r1 = printf("[p NULL] real: %p|\n", null_ptr);
	r2 = ft_printf("[p NULL] mine: %p|\n", null_ptr);
	printf("returns: %d vs %d\n\n", r1, r2);

	/* %% */
	r1 = printf("[%%] real: 100%%|\n");
	r2 = ft_printf("[%%] mine: 100%%|\n");
	printf("returns: %d vs %d\n\n", r1, r2);

	/* mixed: checks that EACH conversion consumes exactly ONE argument */
	r1 = printf("[mix] real: %d %s %c %x %u|\n", 10, "abc", 'z', 255, 99);
	r2 = ft_printf("[mix] mine: %d %s %c %x %u|\n", 10, "abc", 'z', 255, 99);
	printf("returns: %d vs %d\n\n", r1, r2);

	/* no conversion at all */
	r1 = printf("[plain] real: just text|\n");
	r2 = ft_printf("[plain] mine: just text|\n");
	printf("returns: %d vs %d\n", r1, r2);
	return (0);
}