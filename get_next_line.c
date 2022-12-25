/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:10:23 by djacobs           #+#    #+#             */
/*   Updated: 2022/12/23 10:10:25 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static char *give_to_buf(char *buf, char *save, int fd)
{
	int	index;
	int	length;

	index = 0;
	length = 0;
	while (buf[length])
		save[length++] = buf[length];
	save[length] = 0;
	while (read(fd, &buf[index], 1) && (index + length) <= BUFFER_SIZE)
		index++;
	return (save);
}
static char	*current_line(char *save, char *buf, int islast)
{
	if (islast)
	{
		buf = save;
		return (buf);
	}
	else
		return (save);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*save;
	int			index;
	int			swinc;

	swinc = 0;
	index = 0;
	//save = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (*buf)
		return (give_to_buf(buf, save, fd));
	while (index <= BUFFER_SIZE && read(fd, &save[index++], 1))
	{
		if ((save[index-1] == '\n' || swinc) && index <= BUFFER_SIZE)
		{
			if (!read(fd, &buf[swinc++], 1) || buf[swinc] != '\n')
				return (current_line(save, buf, 0));
			else if ((index + swinc) == BUFFER_SIZE)
				return (current_line(save, buf, 1));
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		i = atoi(argv[1]);
	int		fd;

	fd = open("fileread", O_RDWR);
	while (i)
	{
		printf("%s",get_next_line(fd));
		i--;
	}
	return (0);
}