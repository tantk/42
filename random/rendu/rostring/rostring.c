#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isspace(char c)
{
	return (9<= c && c <= 13) || (c == ' ');
}

void	ft_putstr(char *str)
{
	while(*str && !ft_isspace(*str))
	{
		ft_putchar(*str);
		str++;
	}
}
int	ft_strlen(char *str)
{
	int i = 0;
	while(*str && !ft_isspace(*str))
	{
		i++;
		str++;
	}
	return i;
}

char	*ft_strdup(char *str)
{
	int len = 0;
	char *result;
	char *result_ptr;

	len = ft_strlen(str);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return NULL;
	result_ptr = result;
	result[len] = '\0';
	while (*str && !ft_isspace(*str))
	{
		*result_ptr = *str;
		result_ptr++;
		str++;
	}
	return result;
}

int	word_count(char *str)
{
	int wc = 0;

	while(*str)
	{
		if (ft_isspace(*str))
			while(ft_isspace(*str) && *str)
				str++;
		else
		{
			wc++;
			while(!ft_isspace(*str) && *str)
				str++;
		}
	}
	return (wc);
}

char	**ft_split(char *str)
{
	int wc = word_count(str);
	char **arr;
	char **arr_ptr;
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return 0;
	arr_ptr = arr;
	arr[wc] = 0;
	while(*str)
	{
		if (ft_isspace(*str))
			while(ft_isspace(*str) && *str)
				str++;
		else
		{
			*arr_ptr = ft_strdup(str);
			while(!ft_isspace(*str) && *str)
				str++;
			arr_ptr++;
		}
	}
	return arr;
}

int	main(int argc, char** argv)
{
	if (argc == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	int wc = word_count(argv[1]);
	if (wc == 1)
	{
		ft_putstr(argv[1]);
		ft_putchar('\n');
		return (0);
	}
	char **arr  = ft_split(argv[1]);
	char **arr_ptr = arr;
	arr_ptr++;
	while(*arr_ptr)
	{
		ft_putstr(*arr_ptr++);
		ft_putchar(' ');
	}
	ft_putstr(*arr);
	ft_putchar('\n');
/*	
	while (*arr)
	{
		printf("%s\n",*arr);
		arr++;
	}*/
}
