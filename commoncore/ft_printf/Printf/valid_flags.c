#include "libft.h"

int	valid_flags(char c)
{
	if (ft_strchr(CS_FLAGS,c))
		return (1);
	return (0);
}

int	count_flags(char *input)
{
	int	count;

	count = 0;
	while(*input)
	{
		if (*input == '%')
		{
			if (valid_flags(input[1]))
				count++;
		}
		input++;
	}
	return (count);
}

//Assumes char c exists in CS_FLAGS else return -1
int	get_flags_index(char c)
{
	const char *flags = CS_FLAGS;
	int			count;

	count = 0;
	while (*flags)
	{
		if (*flags == c)
			return (count);
		count++;
		flags++;
	}
	return (-1);
}
