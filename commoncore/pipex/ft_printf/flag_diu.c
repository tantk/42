/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_diu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:22:17 by titan             #+#    #+#             */
/*   Updated: 2023/09/29 18:54:34 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_int(int n)
{
	long	nb;
	int		count;

	nb = (long)n;
	count = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
		count++;
	}
	if (nb > 9)
	{
		count += ft_putnbr_int(nb / 10);
		count += ft_putnbr_int(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		count++;
	}
	return (count);
}

static int	ft_putnbr_uint(unsigned int n)
{
	long	nb;
	int		count;

	nb = (long)n;
	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr_uint(nb / 10);
		count += ft_putnbr_uint(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		count++;
	}
	return (count);
}

int	ft_parse_d(va_list *va_ptr)
{
	return (ft_putnbr_int(va_arg(*va_ptr, int)));
}

int	ft_parse_i(va_list *va_ptr)
{
	return (ft_putnbr_int(va_arg(*va_ptr, int)));
}

int	ft_parse_u(va_list *va_ptr)
{
	return (ft_putnbr_uint(va_arg(*va_ptr, unsigned int)));
}
