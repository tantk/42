#include <unistd.h>
#define lowerhex "0123456789abcdef"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned int nb)
{
	char buffer[16];
	int idx = 0;
	if (!nb)
	{
		ft_putchar('0');
		return;
	}
	while (nb)
	{
		buffer[idx] = lowerhex[nb & 0xF];
		nb = nb >> 4;
		idx++;
	}
	idx--;
	while (0 <= idx)
	{
		ft_putchar(buffer[idx]);
		idx--;
	}
}

int	ft_atoi(char *str)
{
	int result = 0;
	int read = 0;
	while(*str)
	{
		read = *str - 48;
		result = result * 10 + read;
		str++;
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_putchar('\n');
	int nb = ft_atoi(argv[1]);
	ft_print_hex(nb);
	ft_putchar('\n');
}
