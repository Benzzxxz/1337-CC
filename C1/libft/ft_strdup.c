/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:08:59 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/15 09:09:06 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*rs;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	rs = malloc(i * sizeof(char) + 1);
	if (!rs)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rs[i] = s[i];
		i++;
	}
	rs[i] = '\0';
	return (rs);
}
