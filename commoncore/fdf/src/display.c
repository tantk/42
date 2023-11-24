/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:02:37 by titan             #+#    #+#             */
/*   Updated: 2023/11/24 08:20:37 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_display	*create_display()
{
	t_display	*disp;
	t_img		*disp_img;

	disp = (t_display *)malloc(sizeof(t_display));
	if (!disp)
		exit_error("create_display malloc error");
	disp_img = (t_img *)malloc(sizeof(t_img));
	if (!disp_img)
		exit_error("create display malloc error");
	disp -> img = disp_img;
	disp -> mlx = mlx_init();
	disp -> mlx_win = mlx_new_window(disp -> mlx, RESO_X, RESO_Y, "FDF");
	disp_img -> img = mlx_new_image(disp -> mlx, RESO_X, RESO_Y);
	disp_img = disp -> img;
	disp_img -> addr = mlx_get_data_addr(disp_img -> img, &disp_img -> b_in_pix,&disp_img -> l_len, &disp_img -> endian);
	return (disp);
}

void	fdf_put_pixel(t_img	*img, int x, int y, int color)
{
	char 	*dst;

	dst = img -> addr + (y * img -> l_len + x * (img -> b_in_pix / 8));
	*(unsigned int *)dst = color;
}
