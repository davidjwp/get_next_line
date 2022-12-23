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

char	*get_next_line(int fd)
{
	static char	*buf;
	int			index;
	int			index2;
	char		*line;

	index = 0;
	index2 = 0;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (read(fd, line, BUFFER_SIZE))
	{
		while (line[index] != '\n' && line[index])
			index++;
		if (line[index] == '\n')
		{
			if (index < BUFFER_SIZE)
			{
				buf = &line[index];
			}
			line[index + 1] = 0;
		}
	}
	else if (buf)
		return (free(line), buf);
	return (line);
}

int	main(int argc, char **argv)
{
	int		i = atoi(argv[1]);
	int		fd;
	//char	buf[BUFFER_SIZE];

	fd = open("fileread", O_RDWR);
	while (i)
	{
		printf("%s",get_next_line(fd));
		i--;
	}
	return (0);
}