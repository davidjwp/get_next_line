#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 100
#endif
char	*ft(char *ft)
{
	int	index = 0;

	ft = malloc (3 * sizeof(char));
	while (index != 3)
		ft[index++] = 'A';

	return (ft);
}
int	main(void)
{
	/*int		fd;
	char	buf[BUFFER_SIZE];

	fd = open("fileread", O_RDWR);
	read(fd, buf,BUFFER_SIZE);
	write( 1, buf, BUFFER_SIZE);
	return (0);*/
	char *ter1;
	char *ter2;

	ter1 = ft(ter2);
	free(ter2);
	return (0);
}