/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:58:40 by titan             #+#    #+#             */
/*   Updated: 2023/11/27 09:22:35 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	linelow(t_img *img, t_int_pt pt1, t_int_pt pt2)
{
	int dx = pt2.x - pt1.x;
	int dy = pt2.y - pt1.y;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	int D = (2 * dy) - dx;
	int y = pt1.y;
	for (int x = pt1.x; x < pt2.x;x++)
	{
		fdf_put_pixel(img, x, y, 0x00ffff);
		if (D > 0)
		{
			y += yi;
			D += (2 *(dy - dx));
		}
		else
			D += 2*dy;
	}
}

void	linehigh(t_img *img, t_int_pt pt1, t_int_pt pt2)
{
	int dx = pt2.x - pt1.x;
	int dy = pt2.y - pt1.y;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	int D = (2 * dx) - dy;
	int x = pt1.x;
	for (int y = pt1.y; y < pt2.y;y++)
	{
		fdf_put_pixel(img, x, y, 0xffff00);
		if (D > 0)
		{
			x += xi;
			D += (2 *(dx - dy));
		}
		else
			D += 2*dx;
	}
}

void	general_line(t_img *img, t_int_pt pt1, t_int_pt pt2)
{
	if (abs(pt2.y - pt1.y) < abs(pt2.x - pt1.x))
	{
		if (pt1.x > pt2.x)
			linelow(img,pt2,pt1);
		else
			linelow(img,pt1, pt2);
	}
	else
	{
		if (pt1.y > pt2.y)
			linehigh(img, pt2, pt1);
		else
			linehigh(img, pt1, pt2);
	}
}

void	draw_line(t_img *img, t_render_pt pt1, t_render_pt pt2)
{
	t_line	line;

	line.pt1.x = (int)lroundf(pt1.x);
	line.pt1.y = (int)lroundf(pt1.y);
	line.pt2.x = (int)lroundf(pt2.x);
	line.pt2.y = (int)lroundf(pt2.y);

	general_line(img, line.pt1,line.pt2);
}

void	draw_last(t_map *map,t_display *disp)
{
	unsigned int	i;
	int				idx;

	i = 0;
	idx = (map -> map_row - 1) * map -> map_col;
	while (i < map -> map_col - 1)
	{
		draw_line(disp -> img, map -> ren_mat[idx],map -> ren_mat[idx+1]);
		idx++;
		i++;
	}
}

void	draw_map(t_map *map,t_display *disp)
{
	unsigned int 	i;
	unsigned int	j;
	int				idx;
	t_render_pt	*ren_mat;

	i = 0;
	j = 0;
	ren_mat = map -> ren_mat;
	while (i < map -> map_row - 1)
	{
		while (j < map -> map_col - 1)
		{
			idx = i * map -> map_col + j;
			draw_line(disp -> img, ren_mat[idx], ren_mat[idx + 1]);
			draw_line(disp -> img, ren_mat[idx], ren_mat[idx + map -> map_col]);
			j++;
		}
		idx++;
		draw_line(disp -> img, ren_mat[idx], ren_mat[idx + map -> map_col]);
		j = 0;
		i++;
	}
	draw_last(map, disp);
	mlx_put_image_to_window(disp -> mlx, disp -> mlx_win, disp -> img -> img, 0, 0);
}
