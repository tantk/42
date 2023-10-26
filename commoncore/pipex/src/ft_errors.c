/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:18:24 by titan             #+#    #+#             */
/*   Updated: 2023/10/27 05:13:34 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	nil_prog_err(char *prog_name)
{
	ft_printf("%s program cannot be found, error: %s",prog_name,strerror(errno));
	return (-1);
}

int ret_errmsg(const char *msg)
{
	perror(msg);
	return (-1);
}

char *ret_errmsg_char(const char *msg)
{
	perror(msg);
	return (NULL);
}

int	ret_err_cust_msg(const char *msg, int errorcode)
{
	ft_printf("Error related to %s \n",strerror(errorcode));
	if (msg)
		ft_printf("%s \n", msg);
	return (-1);
}
//
void	exit_failure()
{	
	exit(EXIT_FAILURE);
}
