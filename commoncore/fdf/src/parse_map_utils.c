/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:59:56 by titan             #+#    #+#             */
/*   Updated: 2024/01/23 21:00:50 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	create_scale(t_map *map)
{
	double	x_range;
	double	y_range;

	x_range = map -> max_x - map -> min_x;
	y_range = map -> max_y - map -> min_y;
	if (x_range > y_range)
		map -> scale = (RESO_X * TARGET) / x_range;
	else
		map -> scale = (RESO_Y * TARGET) / y_range;
}

void	create_shift(t_map *map)
{
	if (map -> min_x >= 0 && map -> min_y >= 0)
		return ;
	if (map -> min_x < map -> min_y)
		map -> shift = -1 * map -> min_x;
	else
		map -> shift = -1 * map -> min_y;
}

void	shift_scale(t_3D *mat ,int i, double shift, double scale)
{
	mat[i].x += shift;
	mat[i].x *= scale;
	mat[i].y += shift;
	mat[i].y *= scale;
}

void	shift_scale2(double *i,double *j, double shift, double scale)
{
	*i += shift;
	*i *= scale;
	*j += shift;
	*j *= scale;
}
