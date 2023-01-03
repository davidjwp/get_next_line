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
			return(free(line), NULL);
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
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i] = '\n';
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
	if (!i)
		return (free(buf), NULL);	
	clear = ft_calloc(i + 1, sizeof(char));
	if (!clear)
		return (free(clear), NULL);
	//might have to check i + 1
	if (buf[i] == '\n')
		i++;
	while (buf[i])
		clear[j++] = buf[i++];
	return (clear);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	buf = read_buf_line(fd, buf);
	if (!buf)
		return (NULL);
	line = give_line(buf);
	buf = clear_buf(buf);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("fileread.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}