/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:01:37 by djacobs           #+#    #+#             */
/*   Updated: 2023/01/04 18:01:38 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

static char	*read_buf_line( int fd, char *buf)
{
	char	*line;
	int		bytes_read;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	bytes_read = 1;
	while (!check_line(buf) && bytes_read)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), free(line), NULL);
		line[bytes_read] = 0;
		buf = ft_strjoin(buf, line);
	}
	return (free(line), buf);
}

static char	*give_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!*buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
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
	if (!*buf)
		return (free(line), NULL);
	return (line);
}

static char	*clear_buf(char *buf)
{
	char	*clear;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	i++;
	clear = malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!clear)
		return (NULL);
	while (buf[i] != '\0')
		clear[j++] = buf[i++];
	clear[j] = 0;
	return (free(buf), clear);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = read_buf_line(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = give_line(buf[fd]);
	buf[fd] = clear_buf(buf[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("fileread.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }