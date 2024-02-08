/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 03:31:52 by titan             #+#    #+#             */
/*   Updated: 2023/11/04 06:27:59 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long long values, const char *hex_char, int fd)
{
	unsigned char	buffer[16];
	int				index;
	int				printed_char;

	index = 0;
	ft_bzero(buffer, 16);
	if (!values)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (values && index < 16)
	{
		buffer[index++] = hex_char[values & 0x0F];
		values = values >> 4;
	}
	printed_char = index;
	while (index > 0)
		ft_putchar_fd(buffer[--index], fd);
	return (printed_char);
}
