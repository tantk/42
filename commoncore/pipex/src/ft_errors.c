/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:18:24 by titan             #+#    #+#             */
/*   Updated: 2023/10/31 12:19:40 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	nil_prog_err(char *prog_name)
{
	ft_printf("%s program cannot be found, error: %s\n",prog_name,strerror(errno));
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
int	exit_status(int status)
{
	if (!WIFEXITED(status))
		ft_printf("exited, status=%d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		ft_printf("killed by signal %d\n", WTERMSIG(status));
	else if (WIFSTOPPED(status))
		ft_printf("stopped by signal %d\n", WSTOPSIG(status));
	if (!WIFEXITED(status))
		return (-1);
	return (1);
}
