/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:02:51 by abenzago          #+#    #+#             */
/*   Updated: 2026/10/12 16:02:52 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;

	x = s;
	i = 0;
	while (i < n)
	{
		*x = c;
		x++;
		i++;
	}
	return (s);
}
int main()
{
	int *p = {202020, 2, 3, 4, 5, 6}
	ft_memset(p[])
}