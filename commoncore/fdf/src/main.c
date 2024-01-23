/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:10:50 by titan             #+#    #+#             */
/*   Updated: 2024/01/23 19:37:58 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_display	*disp;

	if (argc != 2)
		exit_error("argument must be 2");
	map = create_map(argv[1]);
	disp = create_display();
	draw_map(map, disp);
	hook_all(disp, map);
	mlx_loop(disp -> mlx);
	return (0);
}
