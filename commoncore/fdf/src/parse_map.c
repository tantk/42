/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:43:08 by titan             #+#    #+#             */
/*   Updated: 2023/11/10 23:00:40 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//rewrite split
int	parse_line(char *line, t_map *map)
{

	ft_split(line, ',');
	return (1);
}

int	parse_file(char *file_path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file_path,O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, map);
	}

}
