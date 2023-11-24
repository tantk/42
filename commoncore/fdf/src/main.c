/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:10:50 by titan             #+#    #+#             */
/*   Updated: 2023/11/24 08:16:04 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	/*
	(void) argc;
	(void) argv;
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	(void) mlx_win;
	mlx_loop(mlx);*/
	
	t_map		*map;
	t_display	*disp;
	//void *mlx;
	//void *mlx_win;
	if (argc != 2)
		exit_error("argument must be 2");
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, RESO_X, RESO_Y, "FDF");
	//(void)mlx_win;
	map = create_map(argv[1]);
	disp = create_display();
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
printf("min --- x:%.6f , y:%6f \n",
				map -> min_x,
				map -> min_y);
printf("max --- x:%.6f , y:%6f \n",
				map -> max_x,
				map -> max_y);
	//mlx_new_image(mlx, RESO_X,RESO_Y);
	//(void) disp;
	draw_map(map, disp);
	//mlx_put_image_to_window(disp -> mlx, disp -> mlx_win, disp -> img, 0,0);
	//mlx_loop(disp -> mlx);
	mlx_loop(disp -> mlx);
	//free(map -> matrix);
	//free(map);
	return(0);
}
