/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:31:20 by titan             #+#    #+#             */
/*   Updated: 2023/11/13 04:12:52 by titan            ###   ########.fr       */
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

void	extract_color(t_mlst_hld *hld, char **line_add)
{
	char buf[2];
	char *ptr;
	int		i;

	i = 0;
	ptr = *line_add;
	while (i < 6)
	{
		buf[0] = ptr[i + 2];
		buf[1] = ptr[i + 3];
		if (hld -> last -> content -> color)
			hld -> last -> content <<= 2;
		hld -> last -> content -> color += (int)buf;
		i += 2;
	}
	ptr += 9;
}

static void	assign_coord(t_mlst_hld *hld, char **line_add)
{
	char	*ptr;

	ptr = *line_add;
	hld -> last -> content -> x = hld -> cur_col;
	hld -> last -> content -> y = hld -> cur_row;
	hld -> last -> content -> z = fdf_atoi(line_add);
	hld -> cur_col++;
}

void	fdf_parse_line(t_mlst_hld *hld, char *line)
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
		else if ('0' <= *line && *line <= '9')
		{
			fdf_lstadd(hld);
			assign_coord(hld, &line);
		}
		else
			exit_error("fdf_parse_line: unidentified character");
	}
	if (hld -> cur_row != 0 && hld -> cur_col != hld -> col)
		exit_error("fdf_parse_line: map must be rectangle or square.");
	hld -> cur_row++;
	if (!hld -> col)
		hld -> col = hld -> cur_col;
}
