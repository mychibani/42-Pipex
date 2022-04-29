#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	error(char *str)
{
	perror(str);
	exit(1);
}

int	main(int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("open :");
		return (-1);
	}
	write(fd, av[2], strlen(av[2]));
	return (0);
}
