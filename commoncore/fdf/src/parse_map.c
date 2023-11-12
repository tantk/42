/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:08 by titan             #+#    #+#             */
/*   Updated: 2023/11/13 04:40:44 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlst_hld	parse_file(char *file_path, t_map *map)
{
	int			fd;
	char		*line;
	t_mlst_hld	hld;

	hld.head = NULL;
	hld.last = NULL;
	hld.size = 0;
	hld.row = 0;
	hld.col = 0;
	hld.cur_col = 0;
	hld.cur_row = 0;
	fd = open(file_path,O_RDONLY);
	if (fd == -1)
		exit_error("parse_file: open file error fd");
	line = get_next_line(fd);
	while (line)
	{
		fdf_parse_line(&hld, line);
		line = get_next_line(fd);
	}
	return (hld);
}

t_matrix	create_matrix(char *file_path)
{
	
}

t_map	create_map(char *file_path)
{
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit_error("load_map: malloc map fails");
	
}
