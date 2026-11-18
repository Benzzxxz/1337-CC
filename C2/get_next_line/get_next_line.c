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

char	*search(char *str, int fd)
{
	char	*buff;
	int		rd;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	rd = 1;
	if (ft_memchr(str, '\n'))
		return (free(buff), str);
	while (!ft_memchr(buff, '\n') && rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (free(buff), free(str), NULL);
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
char *get_next_line(int fd)
{
	static char	*lftvr;
	char		*line;
	char		*full_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = search(lftvr, fd);
	if (!full_line)
		return (NULL);
	if (full_line[0] == '\0')
		return (free(full_line), NULL);
	line = ft_get_line(full_line);
	lftvr = ft_get_lefovr(full_line);
	free(full_line);
	return(line);
}
