/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:08 by titan             #+#    #+#             */
/*   Updated: 2023/11/14 05:04:13 by titan            ###   ########.fr       */
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

t_matrix	*create_matrix(t_mlst_hld hld)
{
	t_matrix	*mat;

	mat = (t_matrix *)malloc(sizeof(t_matrix));
	if (!mat)
		exit_error("create_matrix malloc fails");
	mat -> mat_row = hld.size;
	mat -> mat_col = sizeof(t_3Dpoint) / sizeof(int);
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
	fd = open(file_path,O_RDONLY);
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

t_map	*create_map(char *file_path)
{
	t_map	*map;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit_error("load_map: malloc map fails");
	map -> matrix = parse_file(map, file_path);
	return (map);
}
