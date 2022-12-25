#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

int	main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE];

	fd = open("fileread", O_RDWR);
	read(fd, buf,BUFFER_SIZE);
	write( 1, buf, BUFFER_SIZE);
	return (0);
}