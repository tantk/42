#include <unistd.h>

void	ft_putchar(char n)
{
	write(1,&n,1);
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	char	*first;
	char	*second;
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	first = argv[1];
	second = argv[2];
	i = 0;

	while (*first && *second)
	{
		if (*first == *second && *second && *first)
		{
			first++;
			second++;
		}
		else
		{
			second++;
		}
	}
	if (*first == '\0')
	{
		ft_putstr(argv[1]);
	}
	ft_putchar('\n');
	return(0);
}
