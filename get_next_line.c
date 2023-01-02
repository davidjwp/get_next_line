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

/*read BUFFER_SIZE file until a newline is found while adding the read bytes to buf*/
char	*read_buf_line(int fd, char *buf)
{
	char	*line;
	int		bytes_read;

	line = ft_calloc( BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	bytes_read = 1;
	while(!check_line(buf) && bytes_read)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
			return(free(buf), NULL);
		buf = ft_strjoin(buf, line);
	}
	return (free(line), buf);
}
/*returns the first line of buf */
char	*give_line(char *buf)
{
	char	*line;
	int		i;

	if (!buf[0])
		return (NULL);
	i = check_line(buf);
	line = ft_calloc(i + 1 , sizeof(char));
	while (i)
	{
		line[i] = buf[i];
		i--;
	}
	return (line);
}

/*returns everything after the newline in buf*/
char	*clear_buf(char *buf)
{
	char	*clear;
	int		i;
	int		j;

	j = 0;
	i = check_line(buf);
	while (buf[i])
		clear[j++] = buf[i++];
	clear[j] = 0;
	return (clear);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = read_buf_line(fd, buf);
	if (!buf)
		return (NULL);
	line = give_line(buf);
	buf = clear_buf(buf);
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