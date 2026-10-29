/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:56:50 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/14 10:56:51 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		t;

	t = 0;
	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		while (little[t] && i < len && big[i] == little[t])
		{
			i++;
			t++;
		}
		if (little[t] == '\0')
			return ((char *)(big + (i - t)));
		i -= t;
		t = 0;
		i++;
	}
	return (NULL);
}
