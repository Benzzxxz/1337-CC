/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <abenzago@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:10:43 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/13 16:10:46 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		s[i++];
	return (i);
}
char *get_leftover(char *src, int buf)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(char) * (BUFFER_SIZE - buf));
	while (src[i])
	{
		dst[i] = src[buf + 1];
		i++;
		buf++;
	}
	dst[i] = '\0';
	//* printf("leftover is : \n------\n%s\n------\n", dst);
	return (dst);
}
char *get_line(char *s, int j)
{
	int		i;
	char	*d;

	i = 0;
	d = malloc(sizeof(char) * j + 1);
	while (i <= j)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	//* printf("your line is : %s", d);
	return(d);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*c;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	c = malloc(sizeof(char) * len + 1);
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	j = ft_strlen(s1);
	while (s2[i - j])
	{
		c[i] = s2[i - j];
		i++;
	}
	c[i] = '\0';
	return (c);
}