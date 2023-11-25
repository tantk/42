/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:58:40 by titan             #+#    #+#             */
/*   Updated: 2023/11/25 22:29:43 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/*static int sign(int num)
{
	if (num > 0)
		return (1);
	if (num < 0)
		return (-1);
	return (0);
}*/
/*
static void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
*/
/*
static void general_line(t_img *img, t_line line)
{
	int i;

	i = 1;
	if (line.dy > line.dx)
		swap(&line.dy,&line.dx);
	else
		line.itc = 0;
	line.E = 2 * line.dy - line.dx;
	line.A = 2 * line.dy;
	line.B = 2 * line.dy - 2 * line.dx;
	fdf_put_pixel(img, line.x, line.y, 0xffffff);
	while (i <= line.dx)
	{
		if (line.E < 0)
		{
			if (line.itc)
				line.y += line.s2;
			else
			{
				line.x += line.s1;
				line.E += line.A;
			}
		}
		else
		{
			line.y += line.s2;
			line.x += line.s1;
			line.E += line.B;
		}
		fdf_put_pixel(img, line.x, line.y, 0xffffff);
		i++;
	}
}*/
/*
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
*/
/*
static void draw_line_ba(t_img *img, t_line line) {
    int x, y, p, dx, dy, sign;

    x = line.x1;
    y = line.y1;

    dx = abs(line.x2 - line.x1);
    dy = abs(line.y2 - line.y1);

    sign = (line.y2 > line.y1) ? 1 : -1;

    if (dx >= dy) {
        p = 2 * dy - dx;
        while (x <= line.x2) {
            fdf_put_pixel(img, x, y, 0xffffff);
            x++;
            if (p < 0)
                p += 2 * dy;
            else {
                p += 2 * (dy - dx);
                y += sign;
            }
        }
    } else {
        p = 2 * dx - dy;
        while (y != line.y2) {
            fdf_put_pixel(img, x, y, 0xffffff);
            y += sign;
            if (p < 0)
                p += 2 * dx;
            else {
                p += 2 * (dx - dy);
                x++;
            }
        }
    }
}*/
/*
plotLineLow(x0, y0, x1, y1)
    dx = x1 - x0
    dy = y1 - y0
    yi = 1
    if dy < 0
        yi = -1
        dy = -dy
    end if
    D = (2 * dy) - dx
    y = y0

    for x from x0 to x1
        plot(x, y)
        if D > 0
            y = y + yi
            D = D + (2 * (dy - dx))
        else
            D = D + 2*dy
        end if
*/
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
/*
	plotLineHigh(x0, y0, x1, y1)
    dx = x1 - x0
    dy = y1 - y0
    xi = 1
    if dx < 0
        xi = -1
        dx = -dx
    end if
    D = (2 * dx) - dy
    x = x0

    for y from y0 to y1
        plot(x, y)
        if D > 0
            x = x + xi
            D = D + (2 * (dx - dy))
        else
            D = D + 2*dx
        end if
 */
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

/*
 * plotLine(x0, y0, x1, y1)
    if abs(y1 - y0) < abs(x1 - x0)
        if x0 > x1
            plotLineLow(x1, y1, x0, y0)
        else
            plotLineLow(x0, y0, x1, y1)
        end if
    else
        if y0 > y1
            plotLineHigh(x1, y1, x0, y0)
        else
            plotLineHigh(x0, y0, x1, y1)
        end if
    end if
 */
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

//	printf("x1:%d y1:%d x2:%d y2:%d\n",line.pt1.x,line.pt1.y,line.pt2.x,line.pt2.y);
	//line.dx = line.x2 - line.x1;
	if (line.dx < 0)
		line.dx *= -1;
	//line.dy = line.y2 - line.y1;
	if (line.dy < 0)
		line.dy *= -1;
	//line.s1 = sign(line.x2 - line.x1);
	//line.s2 = sign(line.y2 - line.y1);
	line.itc = 1;
	//line.x = line.x1;
	//line.y = line.y1;
	general_line(img, line.pt1,line.pt2);
	//draw_line_ba(img, line);
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
	printf("OIDASDASD!");
	printf("stats: minx:%.6f maxx:%6f miny:%.6f maxy:%6f scale:%6f offset_x:%6f offset_y:%6f\n",
			map->min_x,map->max_x,map->min_y,map->max_y,map->scale, map->offset_x, map ->offset_y);
	i = 0;
	j = 0;
	ren_mat = map -> ren_mat;
	while (i < map -> map_row - 1)
	{
		while (j < map -> map_col - 1)
		{
			idx = i * map -> map_col + j;
/*			printf("Original Point: x:%.6f , y:%.6f z:%.6f\n",
					map ->matrix->content[idx].x,
					map ->matrix->content[idx].y,
					map ->matrix->content[idx].z);*/
/*			printf("point 2,idx+1: x:%.6f , y:%.6f z:%.6f\n",
					map ->matrix->content[idx+1].x,
					map ->matrix->content[idx+1].y,
					map ->matrix->content[idx+1].z);*/
			draw_line(disp -> img, ren_mat[idx], ren_mat[idx + 1]);
			/*printf("point 3,idx+col: x:%.6f , y:%.6f z:%.6f\n",
					map ->matrix->content[idx+map -> map_col].x,
					map ->matrix->content[idx+map -> map_col].y,
					map ->matrix->content[idx+map -> map_col].z);
*/
			draw_line(disp -> img, ren_mat[idx], ren_mat[idx + map -> map_col]);
			j++;
		}
		idx++;
		draw_line(disp -> img, ren_mat[idx], ren_mat[idx + map -> map_col]);
		j = 0;
		i++;
	}
	draw_last(map, disp);
	
	/*
	x1:611 y1:395 x2:644 y2:34

	x1:644 y1:338 x2:611 y2:357
	x1:644 y1:338 x2:677 y2:357
	x1:611 y1:357 x2:578 y2:376
	(void) map;
	t_render_pt a = {611,395};
	t_render_pt b = {644,34};
	draw_line(disp-> img, a,b );*/
/*	(void) map;
	t_render_pt b = {677,357};
	t_render_pt c = {578,376};
	t_render_pt a = {644,338};
	draw_line(disp->img, a,b);
	draw_line(disp->img, a,c);*/
	mlx_put_image_to_window(disp -> mlx, disp -> mlx_win, disp -> img -> img, 0, 0);
}
