#include <stdio.h>
#include "get_next_line.h"
#include <time.h>

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

	clock_t start, end;
	double execution_time;
	start = clock();

	for (int i = 0; i < 100; i++)
	{
	char *file = argv[1];
	int fd = open(file,O_RDWR);
	char *line1 = get_next_line(fd);
	char *line2 = get_next_line(fd);
	char *line3 = get_next_line(fd);
	char *line4 = get_next_line(fd);
	char *line5 = get_next_line(fd);
	char *line6 = get_next_line(fd);
	//printf("%s--end\n",line1);
	//printf("%s--end\n",line2);
	//printf("%s--end\n",line3);
	//printf("%s--end\n",line4);
	//printf("%s--end\n",line5);
	//printf("%s--end\n",line6);
	free(line1);
	free(line2);
	free(line3);
	free(line4);
	free(line5);
	free(line6);
	close(fd);
	/*static t_storage storage= {
		0,0,0,NULL,NULL
	};
	char something[] = "abcd";
	char something2[] = "efg";
	ft_lstadd(&storage, something,4);
	ft_lstadd(&storage, something2,3);
	printf("%s\n",storage.head->content);
	printf("%s\n",storage.last->content);
	char *extract = extract_line(&storage, 1);
	printf("extract %s \n",extract);
	store_leftover(&storage,1);
	free(extract);
	printf("leftover %s \n",storage.head->content);
	ft_lstclear(&storage);
	*/
	}
	end= clock();
	execution_time = ((double)(end - start))/ CLOCKS_PER_SEC;
	printf("time: %lf second ",execution_time);
}
