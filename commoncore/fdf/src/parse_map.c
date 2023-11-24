/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:08 by titan             #+#    #+#             */
/*   Updated: 2023/11/24 10:37:49 by titan            ###   ########.fr       */
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

	mat = (t_matrix *)malloc(sizeof(t_matrix));
	if (!mat)
		exit_error("create_matrix malloc fails");
	mat -> mat_row = hld.size;
	mat -> mat_col = 3;
	mat -> content = lst_to_pts(hld);
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
	{
        map -> scale = (map -> reso_x * 0.9) / x_range;
		map -> shift = (map -> reso_x * 0.05) / x_range;
	}
    else
	{
        map -> scale = (map -> reso_y * 0.90) / y_range;
		map -> shift = (map -> reso_y * 0.05) / y_range;
	}
}

void	adjust_position(t_map *map)
{
	if (map -> min_x > 0 && map -> min_y > 0)
		return;
	if (map -> min_x < map -> min_y)
		map -> shift += -1 * map -> min_x;
	else
		map -> shift += -1 * map -> min_y;
}

void	pixelize(t_map *map)
{
	unsigned int i;

	i = 0;
	adjust_position(map);
	while (i < map -> matrix -> mat_row)
	{
		map -> ren_mat[i].x += map -> shift;
		map -> ren_mat[i].x *= map -> scale;
		map -> ren_mat[i].y += map -> shift;
		map -> ren_mat[i].y *= map -> scale;
		map -> ren_mat[i].y = RESO_Y - map -> ren_mat[i].y;
		i++;
	}
	map ->min_x += map -> shift;
	map -> min_x *= map -> scale;
	map ->max_x += map -> shift;
	map -> max_x *= map -> scale;
	map ->min_y += map -> shift;
	map -> min_y *= map -> scale;
	map -> min_y = RESO_Y - map -> min_y;
	map ->max_y += map -> shift;
	map -> max_y *= map -> scale;
	map -> max_y = RESO_Y - map -> max_y;
}

t_map	*create_map(char *file_path)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit_error("load_map: malloc map fails");
	map -> matrix = parse_file(map, file_path);
	map -> reso_x = RESO_X;
	map -> reso_y = RESO_Y;
    map -> min_x = 0;
    map -> max_x = 0;
    map -> min_y = 0;
    map -> max_y = 0;
	fdf_matmul_rndr(map);
	create_scale(map);
	pixelize(map);
	return (map);
}
