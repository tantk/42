/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:48 by titan             #+#    #+#             */
/*   Updated: 2023/10/29 15:26:52 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char **arr = pp_parse_cmd(argv[1]);
	char **ptr_arr = arr;
	while (*arr)
	{
		printf("%s \n",*arr);
		arr++;
	}
	arr = ptr_arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(ptr_arr);
	return (0);
}
