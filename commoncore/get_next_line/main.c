#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
	char buf[5];
	char buf2[5];
	char buf3[5];

	int fd = open("hello.txt",O_RDONLY);
	read(fd,buf, 5);
	printf("%s --end\n",buf);
read(fd,buf2, 5);
read(fd,buf3, 5);
printf("%s --end\n",buf2);
printf("%s --end\n",buf3);

close(fd);
}
