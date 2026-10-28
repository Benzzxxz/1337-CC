/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:17:52 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/13 11:17:53 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	s = src;
	d = dest;
	while (i < n)
	{
		if (dest > src)
			d[n - i - 1] = s[n - i - 1];
		else
			d[i] = s[i];
		i++;
	}
	return (dest);
}
