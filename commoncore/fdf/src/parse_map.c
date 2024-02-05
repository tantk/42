/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:08 by titan             #+#    #+#             */
/*   Updated: 2024/02/05 18:00:08 by titan            ###   ########.fr       */
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
	mat -> content = 0;
	mat -> color_arr = (unsigned int *)malloc(hld.size * sizeof(unsigned int));
	if (!mat -> color_arr)
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
	mat -> content = lst_to_pts(hld);
	return (mat);
}

void	adjust_map(t_map *map, t_3D *mat)
{
	unsigned int	i;

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
