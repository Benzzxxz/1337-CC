#include "ft_printf.h"

int dispatcher(va_list v, char c)
{
	size_t	count;

	count = 0;
	if (c == 'c')
	{
		ft_putchar(va_arg(v, int));
		count++;
	}
	if (c == 's')
	{
		count = putstr(va_arg(v, char *));
	}
	if (c == 'i')
	{
		count = ft_putnbr(va_arg(v, int));
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list	v;
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	va_start(v, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_memchr("cspdiuxX", format[i + 1], 8))
		{
			count += dispatcher(v, ft_memchr("cspdiuxX", format[i + 1], 8));
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}
int main()
{
	int i = ft_printf("benzz %c here %i", 'c', 1916);
	printf("\n%d", i);
}
