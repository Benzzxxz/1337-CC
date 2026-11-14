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

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_leftover(char *src, int buf);
char	*get_line(char *s, int j);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1916
# endif

#endif