/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:01:10 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/17 14:01:15 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negcheck(long *n)
{
	if (*n < 0)
	{
		(*n) = (*n) * -1;
		return (1);
	}
	return (0);
}

static int	nums(long num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		count;
	char	*res;
	int		minus;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	minus = negcheck(&nb);
	count = nums(nb);
	res = malloc(sizeof(char) * (count + 1 + minus));
	if (!res)
		return (NULL);
	res[count + minus] = '\0';
	if (minus == 0)
		count--;
	while (count >= 0)
	{
		res[count] = (nb % 10) + '0';
		nb /= 10;
		count--;
	}
	if (minus == 1)
		res[count + 1] = 45;
	return (res);
}
