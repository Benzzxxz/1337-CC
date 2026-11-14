/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzago <abenzago@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:29:34 by abenzago          #+#    #+#             */
/*   Updated: 2026/11/13 16:29:40 by abenzago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDWR);
	dprintf(fd, "benzz\nwas\nhere");
	lseek(fd, 0, SEEK_SET);
	printf("1st call\n-----\n%s\n-----\n", get_next_line(fd));
	printf("2sd call\n-----\n%s\n-----\n", get_next_line(fd));
	printf("3rd call\n-----\n%s\n-----\n", get_next_line(fd));
}