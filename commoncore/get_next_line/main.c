#include <stdio.h>
#include "get_next_line.h"
void	ft_putchar(char c)
{
	write(1,&c,1);
}
void ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}
/*
int main()
{
	char buf[5];
	char buf2[5];
	char buf3[5];

	int fd = open("hello.txt",O_RDONLY);
	read(fd,buf, 4);
	buf[4] = '\0';
	ft_putstr(buf);
	ft_putstr("End of buffer1\n");
	int fd2 = open("hello.txt",O_RDONLY);
	read(fd2,buf2, 4);
	buf2[4] = '\0';
	read(fd,buf3, 4);
	buf3[4] = '\0';
	ft_putstr(buf2);
	ft_putstr("End of buffer2\n");
	ft_putstr(buf3);
	ft_putstr("End of buffer3\n");
	ft_putstr(buf);
	close(fd);
}*/

int main()
{
	int fd = open("empty.txt",O_RDONLY);
	printf("%s--end\n",get_next_line(fd));
	printf("%s--end\n",get_next_line(fd));

}
