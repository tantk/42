/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:36:56 by titan             #+#    #+#             */
/*   Updated: 2023/11/15 08:00:37 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*matmul_loop(t_matrix *mat_a, t_mat *mat_b, t_matrix *new_mat, int ik[2])
{
	t_3Dpoint	point;
	t_3Dpoint	new_point;

	while (ik[0] < mat_a -> mat_row)
	{
		point = mat_a -> content[ik[0]];
		while (ik[1] < mat_b -> mat_col)
		{
			new_mat -> content[ik[0]];
			ik[1] += 1;
		}
		ijk[1] = 0;
		ijk[0] += 1;
	}
}
// only works for (x row * 3 col )matrix & (3 row * 3 col)
t_matrix	*fdf_matmul(t_matrix *mat_a, t_mat *mat_b)
{
	int			ik[2];
	t_3Dpoint	*new_mat;

	ik[0] = 0;
	ik[1] = 0;
	if (mat_a -> mat_col != mat_b -> mat_row)
		exit_error("matmul: mat a col need to match mat b row");
	new_mat = (t_3Dpoint *)ft_calloc(mat_b -> mat_col * 3 * sizeof(t_3Dpoint));
	if (!new_mat)
		exit_error("matmul: malloc failed");

}
