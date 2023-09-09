/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:03:01 by titan             #+#    #+#             */
/*   Updated: 2023/09/09 19:19:27 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483647)
    {
        ft_putchar_fd('-', fd);
        ft_putchar_fd('2', fd);
        ft_putnbr_fd(147483647, fd);
    }
    else if (n < 0)
    {
        ft_putchar_fd('-',fd);
        ft_putnbr_fd(-n, fd);
    }
    else if (n < 10)
    {
        ft_putchar_fd(n + '0', fd);
        return;
    }
    else
    {
        ft_putnbr_fd(n/10, fd);
        ft_putnbr_fd(n%10, fd);
        return;
    }

}
