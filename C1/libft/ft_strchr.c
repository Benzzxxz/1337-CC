/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:39:55 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/13 20:39:57 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strchr(const char *s, int c)
{
	unsigned char	t;

	t = c;
	while (*s)
	{
		if ((unsigned char)*s == t)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == t)
		return ((char *)s);
	return (NULL);
}
