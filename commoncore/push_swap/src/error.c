/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:00:40 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:03:16 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_err_exit(char *msg)
{
	ft_printf_err("Error:  %s", msg);
	exit(0);
}

int	ft_err_int(char *msg)
{
	ft_printf_err("Error: %s", msg);
	return (0);
}
