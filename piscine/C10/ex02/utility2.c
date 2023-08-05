#include "ft_header.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return i;
}

char *ft_strdup(char *str)
{
	char *s1;
	char *s1_st;

	s1 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s1)
		return 0;
	s1_st = s1;
	while (*str)
		*s1++ = *str++;
	*s1 = '\0';
	return s1_st;
}

int	ft_strlistlen(char **arr)
{
	int	i;

	i = 0;
	while (*arr)
	{
		i++;
		arr++;
	}
	return i;
}

char *ft_strcpy_cont(char *dest, char *src)
{
	while(*src)
		*dest++ = *src++;
	return dest;
}

void	print_error_msg(char *file)
{
	ft_putstr("Problem opening file: ");
	ft_putstr(basename(file));
	ft_putstr(" with error - ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}
