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

/*static char *pass_to_buf(char *buf, char *save, int fd)
{
	int	index;
	int	length;

	index = 0;
	length = 0;
	if (ft_strncmp(save, buf, ft_strlen(buf)))
	{
		while (save[length])
		{
			buf[length] = save[length];
			length++;
		}
		buf[length] = 0;
		while ((index + length) TO_BUF)
		{
			if (read(fd, &save[index], 1))
				index++;
			else
				return (free(save), buf);
		}
	}
	return (free(save), NULL);
}

static int	fill_line_in(char *str, int fd, int line)
{
	int	index;

	index = 0;
	while (read(fd, &str[index++], 1) && (index + line)  TO_BUF)
	{
		if (str[index - 1] == '\n')
			return (1);
	}
	return (0);
}
*/

char	*get_line(int fd)
{
	char	**line;
	char	*save;

	save = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!save)
		return (NULL);
	read(fd, save, BUFFER_SIZE);
	line = ft_split(save, '\n');
	return (free(save), *line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char	*line;
	(void)buf;
	(void)line;
	if (fd < 0 || !BUFFER_SIZE)
		return (0);
	return (get_line(fd)); 
	/*if (*buf)
		return (pass_to_buf(buf, save, fd));
	else if (fill_line_in(buf, fd, 0))
	{
		fill_line_in(save, fd, ft_strlen(buf));
		return (buf);
	}
	else if (fill_line_in(save, fd, ft_strlen(buf)))
		return (NULL);
	else
		return (NULL);*/

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