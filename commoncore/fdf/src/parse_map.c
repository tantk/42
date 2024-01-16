/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:08 by titan             #+#    #+#             */
/*   Updated: 2024/01/16 15:04:14 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_hld(t_mlst_hld *hld)
{
	hld -> head = NULL;
	hld -> last = NULL;
	hld -> size = 0;
	hld -> col = 0;
	hld -> cur_col = 0;
	hld -> cur_row = 0;
}

//color not regarded as part of the matrix
t_matrix	*create_matrix(t_mlst_hld hld)
{
	t_matrix	*mat;

	mat = malloc(sizeof(t_matrix));
	if (!mat)
		exit_error("create_matrix: mat malloc fails");
	mat -> mat_row = hld.size;
	mat -> mat_col = 3;
	mat -> content = (t_3D *)malloc(hld.size * sizeof(t_3D));
	mat -> color_arr = (unsigned int *)malloc(hld.size * sizeof(unsigned int));
	if (!mat -> content || !mat -> color_arr)
		exit_error("create_matrix: mat content malloc fails");
	return (mat);
}

t_matrix	*parse_file(t_map *map, char *file_path)
{
	int			fd;
	char		*line;
	t_matrix	*mat;
	t_mlst_hld	hld;

	init_hld(&hld);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_error("parse_file: open file error fd");
	line = get_next_line(fd);
	while (line)
	{
		fdf_parse_line(&hld, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	map -> map_row = hld.cur_row;
	map -> map_col = hld.col;
	mat = create_matrix(hld);
	return (mat);
}
//populate scale and shift
void    create_scale(t_map *map)
{
    double  x_range;
    double  y_range;

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
		return;
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

void	create_offset(t_map *map)
{
	const unsigned int x_range = map -> max_x - map -> min_x;
	const unsigned int y_range = map -> max_y - map -> min_y;
	unsigned int	start;

	map -> offset_y =  (RESO_Y - y_range)/2;
	start = (RESO_X - x_range)/2;
	map -> offset_x = start - map -> min_x;
	start = (RESO_Y - y_range)/2;
	map -> offset_y = start - map -> min_y;
}


void	adjust_map(t_map *map, t_3D *mat)
{
	unsigned int i;

	i = 0;
	create_scale(map);
	create_shift(map);
	shift_scale2(&map -> min_y, &map -> max_y, map -> shift, map -> scale);
	shift_scale2(&map -> min_x, &map -> max_x, map -> shift, map -> scale);
	create_offset(map);
	map -> min_y = RESO_Y - map -> min_y;
	map -> max_y = RESO_Y - map -> max_y;
	while (i < map -> matrix -> mat_row)
	{
		shift_scale(mat, i, map -> shift, map -> scale);
		shift_scale(mat, i, map -> shift, map -> scale);
		mat[i].x += map -> offset_x;
		mat[i].y += map -> offset_y;
		mat[i].y = RESO_Y - mat[i].y;
		i++;
	}
}


t_map	*create_map(char *file_path)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit_error("load_map: malloc map fails");
	map -> matrix = parse_file(map, file_path);
    map -> min_x = 0;
    map -> max_x = 0;
    map -> min_y = 0;
    map -> max_y = 0;
	fdf_matmul_rndr(map);
	adjust_map(map, map -> matrix -> rndr);
	return (map);
}
