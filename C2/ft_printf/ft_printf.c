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
	if (c == 'c')
		return (ft_putchar((char)va_arg(v, int)), 1);
	if (c == 's')
		return (ft_putstr(va_arg(v, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(v, int)));
	if (c == 'x')
		return (put_hex(va_arg(v, unsigned int), 0));
	if (c == 'X')
		return  (put_hex(va_arg(v, unsigned int), 1));
	if (c == 'p')
		return (put_addr(va_arg(v, void *)));
	if (c == 'u')
		return (ft_putnbr(va_arg(v, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'), 1);
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
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "ft_printf.h"

#define TMP_FILE "/tmp/ft_printf_test.txt"
#define BUF_SIZE 4096

static int	g_saved_fd;
static int	g_total;
static int	g_passed;

static void	start_capture(void)
{
	int	fd;

	fflush(stdout);
	g_saved_fd = dup(1);
	fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, 1);
	close(fd);
}

static int	stop_capture(char *buf)
{
	int	fd;
	int	n;

	fflush(stdout);
	dup2(g_saved_fd, 1);
	close(g_saved_fd);
	fd = open(TMP_FILE, O_RDONLY);
	n = read(fd, buf, BUF_SIZE - 1);
	close(fd);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	return (n);
}

static void	report(const char *name, char *real, int lreal, int rreal,
				char *mine, int lmine, int rmine)
{
	int	same_out;
	int	same_ret;

	same_out = (lreal == lmine && memcmp(real, mine, lreal) == 0);
	same_ret = (rreal == rmine);
	g_total++;
	if (same_out && same_ret)
	{
		g_passed++;
		printf("✅ %s\n", name);
		return ;
	}
	printf("❌ %s\n", name);
	if (!same_out)
		printf("      output -> real: |%s|   mine: |%s|\n", real, mine);
	if (!same_ret)
		printf("      return -> real: %d   mine: %d\n", rreal, rmine);
}

#define T(name, ...) do { \
	char	b1[BUF_SIZE]; \
	char	b2[BUF_SIZE]; \
	int		r1; \
	int		r2; \
	int		l1; \
	int		l2; \
	start_capture(); \
	r1 = printf(__VA_ARGS__); \
	l1 = stop_capture(b1); \
	start_capture(); \
	r2 = ft_printf(__VA_ARGS__); \
	l2 = stop_capture(b2); \
	report(name, b1, l1, r1, b2, l2, r2); \
} while (0)

int	main(void)
{
	int	x = 42;

	printf("--- %%c ---\n");
	T("c letter", "%c", 'A');
	T("c space", "%c", ' ');
	T("c nul byte", "%c", 0);

	printf("--- %%s ---\n");
	T("s normal", "%s", "hello");
	T("s empty", "%s", "");
	T("s NULL", "%s", (char *)NULL);
	T("s with percent inside", "%s", "100%");

	printf("--- %%d / %%i ---\n");
	T("d zero", "%d", 0);
	T("d positive", "%d", 7);
	T("d negative", "%d", -7);
	T("i positive", "%i", 123);
	T("i negative", "%i", -123);
	T("d INT_MAX", "%d", INT_MAX);
	T("d INT_MIN", "%d", INT_MIN);

	printf("--- %%u ---\n");
	T("u zero", "%u", 0);
	T("u normal", "%u", 42);
	T("u UINT_MAX", "%u", UINT_MAX);
	T("u of -1", "%u", -1);

	printf("--- %%x / %%X ---\n");
	T("x zero", "%x", 0);
	T("x 255", "%x", 255);
	T("x 4096", "%x", 4096);
	T("x of -1", "%x", -1);
	T("x UINT_MAX", "%x", UINT_MAX);
	T("X zero", "%X", 0);
	T("X 255", "%X", 255);
	T("X 48879", "%X", 48879);
	T("X of -1", "%X", -1);

	printf("--- %%p ---\n");
	T("p address", "%p", &x);
	T("p NULL", "%p", (void *)0);

	printf("--- %%%% ---\n");
	T("percent alone", "%%");
	T("percent in text", "100%%");
	T("two percents", "%%%%");

	printf("--- combos (bookmark test) ---\n");
	T("plain text", "just text");
	T("empty format", "");
	T("d d", "%d %d", 10, 20);
	T("adjacent dd", "%d%d", 10, 20);
	T("text after conv", "%d apples", 5);
	T("mix 5 types", "%d %s %c %x %u", 10, "abc", 'z', 255, 99);
	T("mix with %%", "%d%%|%s|%c", 50, "ok", 'Z');
	T("p then d", "%p %d", &x, 9);

	printf("\n%d / %d tests passed\n", g_passed, g_total);
	return (g_passed != g_total);
}

