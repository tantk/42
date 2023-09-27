#include "ft_printf.h"

void	ft_parse_c(va_list va_ptr)
{
	fd_putchar_fd(va_arg(va_ptr,char), 1);
}

void	ft_parse_s(va_list va_ptr)
{
	fd_putstr_fd(va_arg(va_ptr,char *), 1);
}

void	ft_parse_p(va_list va_ptr)
{
	unsigned char	*bytes;

	bytes = (unsigned char *)va_arg(va_ptr, void *);	while (*bytes)
	{
		ft_putchar_fd(CS_LOWER_HEX[bytes >> 4], 1);
		ft_putchar_fd(CS_LOWER_HEX[bytes & 0x0F], 1);
		bytes++;
	}
}
