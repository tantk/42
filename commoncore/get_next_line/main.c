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

int main(int argc, char **argv)
{
	/*
	char *file = argv[1];
	int fd = open(file,O_RDWR);
	printf("%s--end\n",get_next_line(fd));
	printf("%s--end\n",get_next_line(fd));
	*/
	static t_storage storage= {
		0,0,0,NULL,NULL
	};
	char something[] = "abcd";
	char something2[] = "efg";
	ft_lstnew(&storage, something,4);
	ft_lstnew(&storage, something2,3);
	printf("%s\n",storage.head->content);
	printf("%s",storage.last->content);
	ft_lstclear(&storage);
}
