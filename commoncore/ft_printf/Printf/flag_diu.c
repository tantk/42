/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_diuxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:22:17 by titan             #+#    #+#             */
/*   Updated: 2023/09/28 02:38:45 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_un(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_un(n / 10);
		ft_putnbr_un(n % 10);
		return ;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		return ;
	}
}

void	ft_parse_d(va_list va_ptr)
{
	ft_putnbr_fd(va_arg(va_ptr, int), 1);
}

void	ft_parse_i(va_list va_ptr)
{
	ft_putnbr_fd(va_arg(va_ptr,int), 1);
}

void	ft_parse_u(va_list va_ptr)
{
	ft_putnbr_un(va_arg(va_ptr, unsigned int));
}
