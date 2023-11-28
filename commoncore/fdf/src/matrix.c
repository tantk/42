/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:36:56 by titan             #+#    #+#             */
/*   Updated: 2023/11/28 21:58:56 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"



static t_render_pt	assign_ren_mat(t_3D mat,t_map *map)
{
	t_render_pt	new_pt;
	new_pt.x = (0.8660254 * mat.x) - (0.8660254 * mat.y);
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
}

// only works for (x row * 3 col )matrix & (3 row * 2 col)
void	fdf_matmul_rndr(t_map *map)
{
	unsigned int	i;
	t_render_pt		*ren_mat;
	t_matrix		*mat;

	mat = map -> matrix;
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
void	rotation_mul(t_matrix *m, t_matrix *mat33)
{
	//algo to get 9 of the items
	mat->content[0];
	//idx to get
	m->content[i]
}

void	fdf_matmul_rotate(t_map *map, t_matrix *mat33)
{
	unsigned int	i;
	t_matrix		*m;
	
	m = map -> matrix;
	if (mat33 -> mat_col != 3 && mat33 -> mat_row != 3)
		exit_error("matmul: mat must be 3*3");
	m -> content = (t_3D *)malloc(map -> matrix -> mat_row * sizeof(t_3D));
	if (!m -> content)
		exit_error("matmul_rotate: malloc failed");
	while (i < map -> matrix -> mat_row)
	{
		mat -> x
	}
}
