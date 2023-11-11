/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:31:20 by titan             #+#    #+#             */
/*   Updated: 2023/11/11 21:04:46 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
void	extract_color(t_map *map, char *str)
{
	char buf[2];

	buf[0] = str[2];
	buf[1] = str[3];

}

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

void	parse_num(t_mlst_hld *hld, char **line_add)
{
	char	*ptr;

	ptr = *line_add;
	
	fdf_atoi(line_add);
	
}

void	parse_hex(t_mlst_hld *hld, char **line_add)
{
	char	*ptr;

	ptr = *line_add;
}

char	**fdf_parse_line(t_mlst_hld *hld, char *line)
{
	hld -> cur_x = 0;

	while (*line && *line != '\n')
	{
		if (*line == ' ' || *line == ',')
			line++;
		else if (*line == '0' && line[1] == 'x')
			parse_hex();
		else if ('0' <= *line && *line <= '9')
			parse_num();
		else
			exit_error("fdf_parse_line: unidentified character");
	}
	if (hld -> row != 0 && hld -> cur_x != hld -> col)
		exit_error("fdf_parse_line: map must be rectangle or square.");
	hld -> cur_y++;
	hld -> row = hld -> cur_x;
}

