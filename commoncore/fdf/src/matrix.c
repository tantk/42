/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:36:56 by titan             #+#    #+#             */
/*   Updated: 2023/11/25 01:50:57 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


/*
static t_render_pt	assign_ren_mat(t_3Dpoint mat,t_map *map)
{
	t_render_pt	new_pt;
	new_pt.x = (-0.8660254 * mat.x) + (0.8660254 * mat.y);
	new_pt.y = (-0.5 * mat.x) - (0.5 * mat.y) + mat.z;
    if (map -> min_x > new_pt.x)
		map -> min_x = new_pt.x;
    else if (map -> max_x < new_pt.x)
		map -> max_x = new_pt.x;
    if (map -> min_y > new_pt.y)
		map -> min_y = new_pt.y;
    else if (map -> max_y < new_pt.y)
		map -> max_y = new_pt.y;
	return (new_pt);
}*/

static t_render_pt	assign_ren_mat(t_3Dpoint mat,t_map *map)
{
	t_render_pt	new_pt;
	new_pt.x = mat.x;
	new_pt.y = mat.y;
    if (map -> min_x > new_pt.x)
		map -> min_x = new_pt.x;
    else if (map -> max_x < new_pt.x)
		map -> max_x = new_pt.x;
    if (map -> min_y > new_pt.y)
		map -> min_y = new_pt.y;
    else if (map -> max_y < new_pt.y)
		map -> max_y = new_pt.y;
	return (new_pt);
}

// only works for (x row * 3 col )matrix & (3 row * 2 col)
void	fdf_matmul_rndr(t_map *map)
{
	unsigned int	i;
	t_render_pt		*ren_mat;
	t_matrix		*mat;

	mat = map -> matrix;
	if (mat -> mat_col != 3)
		exit_error("matmul: mat col must be 3");
	ren_mat = (t_render_pt *)ft_calloc(mat -> mat_row, sizeof(t_render_pt));
	if (!ren_mat)
		exit_error("matmul_rndr: malloc failed");
	i = 0;
	while (i < mat->mat_row)
	{
		ren_mat[i] = assign_ren_mat(mat -> content[i], map);
		i++;
	}
	map -> ren_mat = ren_mat;
}
