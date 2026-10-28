/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:49:39 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/23 15:49:44 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
		i++;
	}
	return (j);
}

static void	frall(char **s, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(s[i]);
	free(s);
}

static void	print(char *src, char *dst, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static char	**spilty(char **chunk, char *s, char c, int words)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (j < words)
	{
		count = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			count++;
			i++;
		}
		chunk[j] = malloc(sizeof(char) * (count + 1));
		if (!chunk[j])
			return (frall(chunk, j), NULL);
		print(s + (i - count), chunk[j], count);
		j++;
	}
	chunk[j] = NULL;
	return (chunk);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	words = countwords((char *)s, c);
	res = malloc(sizeof(char **) * (words + 1));
	if (!res)
		return (NULL);
	res = spilty(res, (char *)s, c, words);
	return (res);
}
