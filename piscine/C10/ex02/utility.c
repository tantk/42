#include "ft_header.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr( char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}
void	ft_putstr_nl(char *str)
{
	if (*str == '\n')
		str++;
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}
int	ft_strcmp(char *s1, char *s2)
{
	while ( *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_atoi(char *str)
{
	int result = 0;
	int read;
	while ('0' <= *str && *str <= '9')
	{
		read = *str - '0';
		result = result * 10 + read;
		str++;
	}
	if (*str)
		return 0;
	return result;
}
