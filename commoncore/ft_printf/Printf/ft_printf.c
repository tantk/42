#include "ft_printf.h"
#include "libft.h"


const ft_parsers	*get_parse_table(void)
{
	ft_parsers parse_table[];

	static const parse_table = {
		ft_parse_c,
		ft_parse_s,
		ft_parse_p
	}
	return (parse_table);
}

void	ft_parse(char c, va_list va_ptr)
{
	int flags_index;

	flags_index = get_flags_index(c);
	if (flags_index != -1)
		get_parse_table()[flags_index](va_ptr);
}



int	ft_printf(char *input, ...)
{
	va_list	va_ptr;
	int		flag_index;

	va_start(va_ptr, count_flags(input));
	while(*input)
	{
		if (*input =='%')
		{
			if (valid_flags(input[1]))
			{
				ft_parse(input[1],va_ptr);
				input++;
			}
		}
		else
			ft_putchar_fd(*input, 1);
		input++;
	}
	va_end(va_ptr);
}
