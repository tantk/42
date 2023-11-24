/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:58:40 by titan             #+#    #+#             */
/*   Updated: 2023/11/24 17:48:26 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_line_ba(t_img *img, t_line line)
{
	int x;
	int	y;
	int p;

	x = line.x1;
	y = line.y1;
	p = 2 * line.dy - line.dx;
	while (x <= line.x2)
	{
		fdf_put_pixel(img, x, y, 0xffffff);
		x++;
		if (p < 0)
			p = p + 2 * line.dy;
		else
		{
			p = p + 2 * line.dy - 2 * line.dx;
			y++;
		}
	}
}

void	draw_line(t_img *img, t_render_pt p1, t_render_pt p2)
{
	t_line	line;

	line.x1 = (int)lroundf(p1.x);
	line.y1 = (int)lroundf(p1.y);
	line.x2 = (int)lroundf(p2.x);
	line.y2 = (int)lroundf(p2.y);
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	draw_line_ba(img, line);
}

void	draw_map(t_map *map,t_display *disp)
{
	int 		i;
	int			j;
	int			idx;
	t_render_pt	*ren_mat;

	i = 0;
	j = 0;
	ren_mat = map -> ren_mat;
	while (i < map -> map_row - 1)
	{
		while (j < map -> map_col - 1)
		{
			idx = i * map -> map_col + j;
			draw_line(disp -> img, ren_mat[idx], ren_mat[idx]);
			draw_line(disp -> img, ren_mat[idx], ren_mat[idx + map -> map_col]);
			j++;
		}
		idx++;
		draw_line(disp -> img, ren_mat[idx], ren_mat[idx + map -> map_col]);
		j = 0;
		i++;
	}
	mlx_put_image_to_window(disp -> mlx, disp -> mlx_win, disp -> img -> img, 0, 0);
}
