/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:02:37 by titan             #+#    #+#             */
/*   Updated: 2024/01/23 19:18:58 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_display	*init_display(void)
{
	t_display	*disp;
	t_img		*disp_img;

	disp = (t_display *)malloc(sizeof(t_display));
	if (!disp)
		exit_error("create_display disp malloc error");
	disp_img = (t_img *)malloc(sizeof(t_img));
	if (!disp_img)
		exit_error("create display disp_img malloc error");
	disp -> img = disp_img;
	return (disp);
}

t_display	*create_display(void)
{
	t_display	*disp;
	t_img		*img;

	disp = init_display();
	img = disp -> img;
	disp -> mlx = mlx_init();
	disp -> mlx_win = mlx_new_window(disp -> mlx, RESO_X, RESO_Y, "FDF");
	disp -> img -> img = mlx_new_image(disp -> mlx, RESO_X, RESO_Y);
	disp -> img = disp -> img;
	img -> addr = mlx_get_data_addr(img -> img,
			&img -> b_in_pix, &img -> l_len, &img -> endian);
	return (disp);
}

void	fdf_put_pixel(t_img	*img, int x, int y, int color)
{
	char	*dst;

	dst = img -> addr + (y * img -> l_len + x * (img -> b_in_pix / 8));
	*(unsigned int *)dst = color;
}
