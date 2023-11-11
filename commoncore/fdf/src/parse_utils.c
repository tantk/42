/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:31:20 by titan             #+#    #+#             */
/*   Updated: 2023/11/11 23:19:21 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_atoi(char **str_add)
{
	int sign;
	int result;
	char *str;

	str = *str_add;
	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	extract_color(t_map *map, char **line_add)
{
	char buf[2];
	char *ptr;

	ptr = *line_add;
	buf[0] = ptr[2];
	buf[1] = ptr[3];
	
}

void	parse_hex(t_mlst_hld *hld, char **line_add)
{
	char	*ptr;

	ptr = *line_add;

}

static void	assign_coord(t_mlst_hld *hld, char **line_add)
{
	char	*ptr;

	ptr = *line_add;
	hld -> last -> content -> x = hld -> cur_x;
	hld -> last -> content -> y = hld -> cur_y;
	hld -> last -> content -> z = fdf_atoi(line_add);
	hld -> cur_x++;
}

void	fdf_parse_line(t_mlst_hld *hld, char *line)
{
	hld -> cur_x = 0;

	while (*line && *line != '\n')
	{
		if (*line == ' ' || *line == ',')
			line++;
		else if (*line == '0' && line[1] == 'x')
		{
			extract_color
			fdf_lstadd(hld);
			assign_coord(hld, &line);
		}
		else if ('0' <= *line && *line <= '9')
		{
			fdf_lstadd(hld);
			assign_coord(hld, &line);
		}
		else
			exit_error("fdf_parse_line: unidentified character");
	}
	if (hld -> row != 0 && hld -> cur_x != hld -> col)
		exit_error("fdf_parse_line: map must be rectangle or square.");
	hld -> cur_y++;
	hld -> row = hld -> cur_x;
}
