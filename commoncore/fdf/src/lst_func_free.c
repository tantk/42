/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:36:29 by titan             #+#    #+#             */
/*   Updated: 2024/02/07 17:50:22 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_hld(t_mlst_hld *hld)
{
	t_mlst	*temp;

	while(hld -> head)
	{
		temp = hld -> head;
		hld -> head = hld -> head -> next;
		free(temp -> content);
		free(temp);
	}
}

void	map_error(t_mlst_hld *hld, char *line, t_map *map)
{
	free_hld(hld);
	while (line)
	{
		if (line)
			free(line);
		line = get_next_line(map -> fd);
	}
	free(map);
	exit_error("fdf_parse_line: map must be rectangle or square.");
}
