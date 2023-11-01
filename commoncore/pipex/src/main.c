/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:48 by titan             #+#    #+#             */
/*   Updated: 2023/11/01 22:32:03 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	err;
	if (argc != 5)
	{
		ft_printf("only accept argument as such: file1 cmd1 cmd2 file2");
		return (1);
	}
	err = pipex(argc, argv, envp);
	if (err == -1)
		exit(EXIT_FAILURE);
	return (0);
}
