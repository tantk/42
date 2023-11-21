/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:10:50 by titan             #+#    #+#             */
/*   Updated: 2023/11/22 06:01:30 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	/*
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	(void) mlx_win;
	mlx_loop(mlx);*/
	(void) argc;
	t_map	*map;
	t_3Dpoint	*ptr;

	map = create_map(argv[1]);
	ptr = map -> matrix -> content;
	int size = map -> map_row * map -> map_col;
	int i = 0;
	while (i < size)
	{
		printf("matrix --- x:%.6f , y:%.6f z:%.6f color:%x",
				map -> matrix -> content -> x,
				map -> matrix -> content -> y,
				map -> matrix -> content -> z,
				map -> matrix -> content -> color);
		printf("rndr --- x:%.6f , y:%6f \n",
				map -> ren_mat -> x,
				map -> ren_mat -> y);
		map -> matrix -> content++;
		map -> ren_mat ++;
		i++;
	}
	free(ptr);
	free(map -> matrix);
	free(map);
}
