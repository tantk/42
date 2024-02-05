/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:21:40 by titan             #+#    #+#             */
/*   Updated: 2024/02/05 18:35:04 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	linehigh_help(t_img *img, t_line l)
{
	l.y = l.pt1.y;
	while (l.y < l.pt2.y)
	{
		fdf_put_pixel(img, l.x, l.y, 0xff0000);
		if (l.D > 0)
		{
			l.x += l.xi;
			l.D += (2 * (l.dx - l.dy));
		}
		else
			l.D += 2 * l.dx;
		l.y++;
	}
}

void	linelow_help(t_img *img, t_line l)
{
	l.x = l.pt1.x;
	while (l.x < l.pt2.x)
	{
		fdf_put_pixel(img, l.x, l.y, 0x00ff00);
		if (l.D > 0)
		{
			l.y += l.yi;
			l.D += (2 * (l.dy - l.dx));
		}
		else
			l.D += 2 * l.dy;
		l.x++;
	}
}

void	linelow(t_img *img, t_int_pt pt1, t_int_pt pt2)
{
	t_line	l;

	l.dx = pt2.x - pt1.x;
	l.dy = pt2.y - pt1.y;
	l.yi = 1;
	if (l.dy < 0)
	{
		l.yi = -1;
		l.dy *= -1;
	}
	l.D = (2 * l.dy) - l.dx;
	l.pt1 = pt1;
	l.pt2 = pt2;
	l.x = pt1.x;
	l.y = pt1.y;
	linelow_help(img, l);
}

void	linehigh(t_img *img, t_int_pt pt1, t_int_pt pt2)
{
	t_line	l;

	l.dx = pt2.x - pt1.x;
	l.dy = pt2.y - pt1.y;
	l.xi = 1;
	if (l.dx < 0)
	{
		l.xi = -1;
		l.dx *= -1;
	}
	l.D = (2 * l.dx) - l.dy;
	l.x = pt1.x;
	l.pt1 = pt1;
	l.pt2 = pt2;
	l.y = pt1.y;
	linehigh_help(img, l);
}

void	general_line(t_img *img, t_int_pt pt1, t_int_pt pt2)
{
	if (abs(pt2.y - pt1.y) < abs(pt2.x - pt1.x))
	{
		if (pt1.x > pt2.x)
			linelow(img, pt2, pt1);
		else
			linelow(img, pt1, pt2);
	}
	else
	{
		if (pt1.y > pt2.y)
			linehigh(img, pt2, pt1);
		else
			linehigh(img, pt1, pt2);
	}
}
