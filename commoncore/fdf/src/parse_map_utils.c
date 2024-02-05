/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:59:56 by titan             #+#    #+#             */
/*   Updated: 2024/02/05 17:59:10 by titan            ###   ########.fr       */
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

void	shift_scale(t_3D *mat, int i, double shift, double scale)
{
	mat[i].x += shift;
	mat[i].x *= scale;
	mat[i].y += shift;
	mat[i].y *= scale;
}

void	shift_scale2(double *i, double *j, double shift, double scale)
{
	*i += shift;
	*i *= scale;
	*j += shift;
	*j *= scale;
}

void	create_offset(t_map *map)
{
	const unsigned int	x_range = map -> max_x - map -> min_x;
	const unsigned int	y_range = map -> max_y - map -> min_y;
	unsigned int		start;

	map -> offset_y = (RESO_Y - y_range) / 2;
	start = (RESO_X - x_range) / 2;
	map -> offset_x = start - map -> min_x;
	start = (RESO_Y - y_range) / 2;
	map -> offset_y = start - map -> min_y;
}
