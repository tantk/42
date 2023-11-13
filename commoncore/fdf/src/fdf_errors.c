/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:18:24 by titan             #+#    #+#             */
/*   Updated: 2023/11/14 01:11:18 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//each program is launched individually, dont terminate

int	ret_errmsg(const char *msg)
{
	perror(msg);
	return (-1);
}

char	*ret_errmsg_char(const char *msg)
{
	perror(msg);
	return (NULL);
}

int	ret_err_cust_msg(const char *msg, int errorcode)
{
	ft_printf_err("Error related to %s \n", strerror(errorcode));
	if (msg)
		ft_printf_err("%s \n", msg);
	return (-1);
}

void	exit_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	error_unknown_char(char c, char *line)
{
	ft_printf_err("Error fdf_parse_line unknown char: %c at line %s", c, line);
	exit(EXIT_FAILURE);
}
