/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:48 by titan             #+#    #+#             */
/*   Updated: 2023/11/04 08:00:44 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	err;

	if (argc != 5)
	{
		ft_printf_err("only accept argument as such: file1 cmd1 cmd2 file2\n");
		return (1);
	}
	err = pipex(argc, argv, envp);
	if (err == -1)
		exit(EXIT_FAILURE);
	return (0);
}
