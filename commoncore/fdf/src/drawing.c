/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:58:40 by titan             #+#    #+#             */
/*   Updated: 2024/02/05 17:54:22 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_img *img, t_3D pt1, t_3D pt2)
{
	t_line	line;

	line.pt1.x = (int)lroundf(pt1.x);
	line.pt1.y = (int)lroundf(pt1.y);
	line.pt2.x = (int)lroundf(pt2.x);
	line.pt2.y = (int)lroundf(pt2.y);
	general_line(img, line.pt1, line.pt2);
}

void	draw_last(t_draw_map d)
{
	unsigned int	i;
	int				idx;

	i = 0;
	idx = (d.map_row - 1) * d.map_col;
	while (i < d.map_col - 1)
	{
		draw_line(d.img, d.rndr[idx], d.rndr[idx + 1]);
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

void	draw_map(t_map *map, t_display *disp)
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
