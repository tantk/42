/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:39:10 by titan             #+#    #+#             */
/*   Updated: 2023/09/30 05:15:12 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//assumes unsigned int
int	ft_parse_x(va_list *va_ptr)
{
	unsigned int	nb;

	nb = va_arg(*va_ptr, unsigned int);
	return (print_hex(nb, CS_LOWER_HEX));
}

int	ft_parse_ux(va_list *va_ptr)
{
	unsigned int	nb;

	nb = va_arg(*va_ptr, unsigned int);
	return (print_hex(nb, CS_UPPER_HEX));
}

int	ft_parse_percent(va_list *va_ptr)
{
	(void)va_ptr;
	ft_putchar_fd('%', 1);
	return (1);
}
