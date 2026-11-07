/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:43:16 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/06 18:43:18 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_putstr(char *s)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

void	rev_putstr(char *s)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		ft_putchar(s[i - 1]);
		i--;
	}
}
