/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:19:18 by titan             #+#    #+#             */
/*   Updated: 2023/11/04 06:43:21 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_c(va_list *va_ptr, int fd)
{
	ft_putchar_fd(va_arg(*va_ptr, int), fd);
	return (1);
}

int	ft_parse_s(va_list *va_ptr, int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(*va_ptr, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
		i++;
	}
	return (i);
}

int	ft_parse_p(va_list *va_ptr, int fd)
{
	unsigned long long	address;

	address = (unsigned long long)va_arg(*va_ptr, void *);
	if (address == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	return (2 + print_hex(address, CS_LOWER_HEX, fd));
}
