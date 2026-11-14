/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <abenzago@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:10:12 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/13 16:10:18 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_line(char *leftover, char *s, int *counter)
{
	while (s[*counter])
	{
		if (s[*counter] == '\n')
		{
			leftover = get_leftover(s, *counter);
			if (leftover != NULL)
				return (ft_strjoin(get_line(s, *counter), leftover));
			return (get_line(s, *counter));
		}
		counter++;
	}
	return (NULL);
}
char *get_next_line(int fd)
{
	static char *leftover;
	char	*s;
	int counter;

	leftover = NULL;
	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	counter = 0;
	while (1)
	{
		read(fd, s, BUFFER_SIZE);
		if (check_line(leftover, s, &counter))
			return (check_line(leftover, s, &counter));
		else
			check_line(leftover, s, &counter);
	}
}
