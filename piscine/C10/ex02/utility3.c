#include "ft_header.h"

int	count_newlines(char *str)
{
	int	lines;

	lines = 0;
	while(*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return lines;
}

int *get_newlines_pos(char *str,int newlines)
{
	int	*newlines_arr;
	int *newlines_arr_st;
	int byte_pos;

	byte_pos = 0;
	newlines_arr = malloc(newlines * sizeof(int));
	if (!newlines_arr)
		return NULL;
	newlines_arr_st = newlines_arr;
	while(*str)
	{
		if (*str == '\n')
			*newlines_arr++ = byte_pos;
		str++;
		byte_pos++;
	}
	return newlines_arr_st;
}
