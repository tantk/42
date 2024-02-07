/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:31:20 by titan             #+#    #+#             */
/*   Updated: 2024/02/07 19:28:10 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_atoi(char **str_add)
{
	int		sign;
	int		result;
	char	*str;

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
	*str_add = str;
	return (result * sign);
}

unsigned int	hex_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return ((unsigned int)(c - '0'));
	else if ('a' <= c && c <= 'f')
		return ((unsigned int)(c - 'a' + 10));
	else if ('A' <= c && c <= 'F')
		return ((unsigned int)(c - 'A' + 10));
	return (0);
}

void	extract_color(t_mlst_hld *hld, char **line_add)
{
	char	*ptr;
	int		pad;

	pad = 0;
	ptr = *line_add;
	ptr += 2;
	while (*ptr && *ptr != ' ' && *ptr != '\n')
	{
		if (hld -> last -> content -> color)
			hld -> last -> content -> color <<= 4;
		hld -> last -> content -> color += hex_to_int(*ptr);
		ptr++;
		pad++;
	}
	while (*ptr && *ptr == ' ')
		ptr++;
	*line_add = ptr;
	while (pad < 6)
	{
		hld -> last -> content -> color <<= 4;
		pad++;
	}
}

static void	assign_coord(t_mlst_hld *hld, char **line_add)
{
	hld -> last -> content -> x = (double)hld -> cur_col;
	hld -> last -> content -> y = (double)hld -> cur_row;
	hld -> last -> content -> z = (double)fdf_atoi(line_add);
	hld -> cur_col++;
	hld -> size++;
}

void	fdf_parse_line(t_mlst_hld *hld, char *line, t_map *map, char *line2)
{
	hld -> cur_col = 0;
	while (*line && *line != '\n')
	{
		if (*line == ' ' || *line == ',')
			line++;
		else if (*line == '0' && line[1] == 'x')
		{
			fdf_lstadd(hld);
			extract_color(hld, &line);
			assign_coord(hld, &line);
		}
		else if (ft_isdigit(*line) || (*line == '-' && ft_isdigit(line[1])))
		{
			fdf_lstadd(hld);
			assign_coord(hld, &line);
		}
		else
			error_unknown_char(*line, hld, line2, map);
	}
	if (hld -> cur_row != 0 && hld -> cur_col != hld -> col)
		map_error(hld, line2, map);
	hld -> cur_row++;
	if (!hld -> col)
		hld -> col = hld -> cur_col;
}
