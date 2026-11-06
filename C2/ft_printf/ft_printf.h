#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (*str);
		i++;
		str++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	putstr(char *s)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int countnum(int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
int	ft_putnbr(int n)
{
	char	res[12];
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (0);
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb > 0)
	{
		res[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		write(1, &res[i--], 1);
	return (countnum(n));
}

void upper(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'f')
			*s = *s - 32;
		s++;
	}
}

int put_hex(int nb, int cs)
{
	int i;
	char hex[17] = "0123456789abcdef";
	char c[20];

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



#endif