/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:18:24 by titan             #+#    #+#             */
/*   Updated: 2023/11/04 08:05:23 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

//each program is launched individually, dont terminate
int	nil_prog_err(char *prog_name)
{
	ft_printf_err("%s program not found,: %s\n", prog_name, strerror(errno));
	return (-1);
}

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

int	exit_status(int status)
{
	if (WEXITSTATUS(status))
		ft_printf_err("Abnormal exit, status=%d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		ft_printf_err("killed by signal %d\n", WTERMSIG(status));
	else if (WIFSTOPPED(status))
		ft_printf_err("stopped by signal %d\n", WSTOPSIG(status));
	if (WEXITSTATUS(status))
		return (-1);
	return (1);
}
