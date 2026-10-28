/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:18:01 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/13 21:18:06 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	t;

	t = c;
	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	while (i > 0)
	{
		if (*s == t)
			return ((char *)s);
		i--;
		s--;
	}
	if (*s == t)
		return ((char *)s);
	return (NULL);
}
