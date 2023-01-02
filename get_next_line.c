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

char *read_buf_line(int fd, char *buf)
{
	char	*line;
	int		bytes_read;

	line = ft_calloc( BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while(!check_line(buf) && bytes_read)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
			return(free(buf), NULL);
		buf = ft_strjoin(buf, line);
	}
	free(line);
	return (buf);
}

char *give_line(char *buf)
{
	char *line;

	line = ft_calloc();
	return ();
}

char	*get_next_line(int fd)
{
	static char	buf;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = read_buf_line(fd, buf);
	if (!buf)
		return (NULL);
		/*give the return line to line*/
	line = give_line(buf);
	/*clear the return from the buf array*/
	buf = ;
	return (line);
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
	(void)argc;
	return (0);
}