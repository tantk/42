/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:08 by titan             #+#    #+#             */
/*   Updated: 2023/11/22 05:25:19 by titan            ###   ########.fr       */
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

static double   preset_scale()

void    create_scale(t_map *map)
{
    double  x_range;
    double  y_range;

    x_range = map -> max_x - map -> min_x;
    y_range = map -> max_y - map -> min_y;
    if (x_range > y_range)
        map -> scale = (map -> resolution_x * 0.9) / x_range;
    else
        map -> scale = (map -> resolution_y * 0.9) / y_range;
}

int pos_position(t_map *map)
{
    int shift;

    shift = 0;
    if (map -> min_x > 0 && map -> min_y > 0)
        return (shift);
    if (map -> min_x < map -> min_y)
        shift = -1 * map -> min_x;
    else
        shift = -1 * map -> min_y;
    return (shift);
}

void    pixelize(t_map *map)
{
    int i;
    int shift;

    i = 0;
    shift = pos_position(map);
    while (i < map -> map_row)
    {
        map -> ren_mat -> x +=shift;
        map -> ren_mat -> x *= map -> scale;
        map -> ren_mat -> y += shift;
        map -> ren_mat -> y *= map -> scale;
    }
}

t_map	*create_map(char *file_path)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit_error("load_map: malloc map fails");
	map -> matrix = parse_file(map, file_path);
	map -> resolution_x = 1024;
	map -> resolution_y = 1024;
    map -> min_x = 0;
    map -> max_x = 0;
    map -> min_y = 0;
    map -> max_y = 0;
	fdf_matmul_rndr(map);
    create_scale(map);
	return (map);
}
