/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:22:33 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/15 13:22:34 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*s;
	size_t	k;

	k = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	else if (nmemb > SIZE_MAX / size)
		return (NULL);
	k = nmemb * size;
	s = malloc(k);
	if (!s)
		return (NULL);
	ft_bzero(s, k);
	return (s);
}
