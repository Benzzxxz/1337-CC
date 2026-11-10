/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:48:26 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/06 17:48:28 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	ft_memchr(const void *s, int c, size_t n);
int		ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		put_hex(unsigned long nb, int cs);
int		put_addr(void *p);
void	rev_putstr(char *s);
int		ft_printf(const char *format, ...);

#endif
