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


static char	*current_line(char *line, char *buf, int index, int fd)
{
	int buf_length;

	if (!index == BUFFER_SIZE)
	{
		buf_length = 0;
		while (line[++index] != '\n')
			buf[buf_length++] = line[index];
		if (line[index] == '\n')
			return (buf[0] = '\n', read(fd, line, BUFFER_SIZE), line); 
	}
	return (read(fd, line, BUFFER_SIZE), line);
}	

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	int			index;
	char		*rline;
	char		*save;

	save = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	index = 0;
	if (!buf[0])
	{
		while (index < BUFFER_SIZE && read(fd, rline, 1))
		{
			if (*rline == '\n')
				return (current_line(rline, buf, index, fd));
			save[index++] = *rline;
		}
		if (!buf[0])
			return ();
	}
	return (buf);
	
	
	
	/*line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		if (read(fd, line, BUFFER_SIZE))
		{
			while (line[index] && line[index] != '\n')
				index++;
			if (line[index] == '\n')
			{
				while (line[index])
			}
		}
		else
			return (get_first_line(line));
	}
	else
	{

	}*/
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