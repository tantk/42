#include <mlx.h>
#include "fdf.h"

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
	parse_file(argv[1]);
}
