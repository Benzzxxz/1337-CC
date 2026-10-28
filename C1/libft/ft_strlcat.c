/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:06:24 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/13 17:06:25 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	t;
	size_t	dstlen;
	size_t	srclen;

	t = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	dstlen = 0;
	while (dstlen < size && dst[dstlen])
		dstlen++;
	i = dstlen;
	if (i >= size)
		return (size + srclen);
	while (i < size - 1 && src[t])
	{
		dst[i] = src[t];
		i++;
		t++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
