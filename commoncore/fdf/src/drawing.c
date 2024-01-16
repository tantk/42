/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:58:40 by titan             #+#    #+#             */
/*   Updated: 2024/01/16 18:53:30 by titan            ###   ########.fr       */
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
		fdf_put_pixel(img, x, y, 0xff0000);
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

void	draw_line(t_img *img, t_3D pt1, t_3D pt2)
{
	t_line	line;

	line.pt1.x = (int)lroundf(pt1.x);
	line.pt1.y = (int)lroundf(pt1.y);
	line.pt2.x = (int)lroundf(pt2.x);
	line.pt2.y = (int)lroundf(pt2.y);

	general_line(img, line.pt1,line.pt2);
}

void	draw_last(t_draw_map d)
{
	unsigned int	i;
	int				idx;

	i = 0;
	idx = (d.map_row - 1) * d.map_col;
	while (i < d.map_col - 1)
	{
		draw_line(d.img, d.rndr[idx], d.rndr[idx+1]);
		idx++;
		i++;
	}
}

void	draw_map_loop(t_draw_map d)
{

	while (d.i < d.map_row - 1)
	{
		while (d.j < d.map_col - 1)
		{
			d.idx = d.i * d.map_col + d.j;
			draw_line(d.img, d.rndr[d.idx], d.rndr[d.idx + 1]);
			draw_line(d.img, d.rndr[d.idx], d.rndr[d.idx + d.map_col]);
			d.j++;
		}
		d.idx++;
		draw_line(d.img, d.rndr[d.idx], d.rndr[d.idx + d.map_col]);
		d.j = 0;
		d.i++;
	}
	draw_last(d);
}

void	draw_map(t_map *map,t_display *disp)
{
	t_draw_map	draw;
	t_img		*img;

	draw.i = 0;
	draw.j = 0;
	draw.idx = 0;
	draw.map_row = map -> map_row;
	draw.map_col = map -> map_col;
	draw.rndr = map -> matrix -> rndr;
	draw.img = disp -> img;
	img = disp -> img;
	draw_map_loop(draw);
	mlx_put_image_to_window(disp->mlx, disp -> mlx_win, img -> img, 0, 0);
}
