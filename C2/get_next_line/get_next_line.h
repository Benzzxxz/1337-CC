/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <abenzago@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:10:29 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/13 16:10:31 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int	ft_memchr(char *s, char c);
int		sepchr(char *s);
char	*ft_get_line(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_get_lefovr(char *s);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif