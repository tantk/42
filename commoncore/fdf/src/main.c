/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:10:50 by titan             #+#    #+#             */
/*   Updated: 2024/01/16 17:08:12 by titan            ###   ########.fr       */
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
	//mlx_new_image(mlx, RESO_X,RESO_Y);
	//(void) disp;
	draw_map(map, disp);
	//hook_all(disp,map);
	//mlx_put_image_to_window(disp -> mlx, disp -> mlx_win, disp -> img, 0,0);
	//mlx_loop(disp -> mlx);
	mlx_loop(disp -> mlx);
	//free(map -> matrix);
	//free(map);
	return(0);
}
