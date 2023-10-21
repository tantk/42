#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	fd = open("dup.txt", O_WRONLY|O_CREAT,0644);
	dup2(fd,STDOUT_FILENO);

	printf("second this is printing toa file! \n");
	close(fd);
	return(0);
}
