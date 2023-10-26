/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:48 by titan             #+#    #+#             */
/*   Updated: 2023/10/25 15:28:48 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("test size of my struct : %ld", sizeof(t_lst_holder));
	return (0);
}
