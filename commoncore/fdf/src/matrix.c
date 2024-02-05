/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:36:56 by titan             #+#    #+#             */
/*   Updated: 2024/02/05 19:23:04 by titan            ###   ########.fr       */
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
