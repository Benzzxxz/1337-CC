/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:21:46 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/15 16:21:47 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy(size_t len, size_t strt, char *d, char *s)
{
	size_t	i;

	i = 0;
	while (i < len && s[strt])
	{
		d[i] = s[strt];
		i++;
		strt++;
	}
	d[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sl;
	char	*c;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (sl <= start)
	{
		c = malloc(1);
		if (!c)
			return (NULL);
		*c = '\0';
		return (c);
	}
	if (len > sl - start)
		len = sl - start;
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	cpy(len, start, c, (char *)s);
	return (c);
}
