/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <abenzago@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:10:12 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/13 16:10:18 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *s)
{
	char	*line;
	int		j;
	int		i;

	j = 0;
	i = sepchr(s);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = s[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_get_lefovr(char *s)
{
	char	*lftvr;
	int		j;
	int		i;

	i = 0;
	j = sepchr(s);
	lftvr = malloc(ft_strlen(s) - j + 1);
	if (!lftvr)
		return (NULL);
	while (s[j])
	{
		lftvr[i] = s[j];
		i++;
		j++;
	}
	lftvr[i] = '\0';
	return (lftvr);
}

int	ft_memchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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

char	*get_next_line(int fd)
{
	static char	*lftvr[1024];
	char		*line;
	char		*full_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	full_line = search(lftvr[fd], fd);
	if (!full_line)
		return (NULL);
	if (full_line[0] == '\0')
		return (free(full_line), NULL);
	line = ft_get_line(full_line);
	lftvr[fd] = ft_get_lefovr(full_line);
	free(full_line);
	return (line);
}
