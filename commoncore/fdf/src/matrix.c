/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:36:56 by titan             #+#    #+#             */
/*   Updated: 2024/01/23 19:40:59 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_3D	assign_ren_mat(t_3D mat, t_map *map)
{
	t_3D	new_pt;

	new_pt.x = 0;
	new_pt.y = 0;
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

t_3D	rdnr_mat(t_3D mat)
{
	t_3D	new_pt;

	new_pt.x = (0.8660254 * mat.x) - (0.8660254 * mat.y);
	new_pt.y = (-0.5 * mat.x) - (0.5 * mat.y) + mat.z;
	return (new_pt);
}

// only works for (x row * 3 col )matrix & (3 row * 2 col)
void	fdf_matmul_rndr(t_map *map)
{
	unsigned int	i;
	t_matrix		*mat;
	t_3D			*rndr;

	mat = map -> matrix;
	rndr = (t_3D *)malloc((mat -> mat_row) * sizeof(t_3D));
	if (!rndr)
		exit_error("matmul_rndr: malloc failed");
	i = 0;
	while (i < mat -> mat_row)
	{
		rndr[i] = assign_ren_mat(mat -> content[i], map);
		i++;
	}
	mat -> rndr = rndr;
}

static t_3D	rotate_mul_row(t_3D row, t_3D *cnt)
{
	t_3D	new_row;

	new_row.x = row.x * cnt[0].x + row.y * cnt[1].x + row.z * cnt[2].x;
	new_row.y = row.x * cnt[0].y + row.y * cnt[1].y + row.z * cnt[2].y;
	new_row.z = row.x * cnt[0].z + row.y * cnt[1].z + row.z * cnt[2].z;
	return (new_row);
}

void	fdf_matmul_rotate(t_map *map, t_matrix *mat33)
{
	unsigned int	i;
	t_3D			*m;
	t_3D			row;

	i = 0;
	if (mat33 -> mat_col != 3 && mat33 -> mat_row != 3)
		exit_error("matmul: mat must be 3*3");
	m = (t_3D *)malloc(map -> matrix -> mat_row * sizeof(t_3D));
	if (!m)
		exit_error("matmul_rotate: malloc failed");
	while (i < map -> matrix -> mat_row)
	{
		row = map -> matrix -> content[i];
		m[i] = rotate_mul_row(row, mat33 -> content);
		i++;
	}
	free(map -> matrix -> content);
	map -> matrix -> content = m;
}
