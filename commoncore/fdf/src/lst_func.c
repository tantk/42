/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:53:38 by titan             #+#    #+#             */
/*   Updated: 2023/11/14 23:23:38 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_3Dpoint	*create_empty_pt(void)
{
	t_3Dpoint	*pt;

	pt = (t_3Dpoint *)malloc(sizeof(t_3Dpoint));
	if (!pt)
		exit_error("create_empty_pt:malloc error");
	pt -> x = 0;
	pt -> y = 0;
	pt -> z = 0;
	pt -> color = 0;
	return (pt);
}

void	fdf_lstadd(t_mlst_hld *hld)
{
	t_mlst	*new_node;

	new_node = (t_mlst *)malloc(sizeof(t_mlst));
	if (!new_node)
		exit_error("fdf_lstadd malloc failure");
	new_node -> content = create_empty_pt();
	new_node -> next = NULL;
	if (!hld -> head)
	{
		hld -> head = new_node;
		hld -> size = 0;
	}
	else
		hld -> last -> next = new_node;
	hld -> last = new_node;
	hld -> size ++;
}

t_3Dpoint	*lst_to_pts(t_mlst_hld hld)
{
	t_3Dpoint	*pts;
	t_3Dpoint	*pts_ptr;
	t_mlst		*temp_mlst;

	pts = (t_3Dpoint *)malloc(hld.size * sizeof(t_3Dpoint));
	if (!pts)
		exit_error("lst_to_pts: malloc fails");
	pts_ptr = pts;
	while (hld.head)
	{
		pts_ptr -> x = hld.head -> content -> x;
		pts_ptr -> y = hld.head -> content -> y;
		pts_ptr -> z = hld.head -> content -> z;
		pts_ptr -> color = hld.head -> content -> color;
		temp_mlst = hld.head;
		hld.head = hld.head -> next;
		free(temp_mlst -> content);
		free(temp_mlst);
		pts_ptr++;
	}
	return (pts);
}

int 	*gen_row(int x, int y, int z, int color)
{
	int	*row;

	row = (int *)malloc(sizeof(int) * 4);
	if (!row)
		exit_error("gen_row: malloc fails");
	row[0] = x;
	row[1] = y;
	row[2] = z;
	row[3] = color;
	return (row);
}

int	**lst_to_mat(t_mlst_hld hld)
{
	int		**matrix;
	int		**mat_ptr;
	t_mlst	*temp_mlst;

	matrix = (int **)malloc(hld.cur_row * sizeof(int *));
	if (!matrix)
		exit_error("lst_to_pts: malloc fails");
	mat_ptr = matrix;
	while (hld.head)
	{
		*mat_ptr = gen_row(hld.head -> content -> x,hld.head -> content -> y,
				hld.head -> content -> z, (int)hld.head -> content ->color);
		temp_mlst = hld.head;
		hld.head = hld.head -> next;
		free(temp_mlst -> content);
		free(temp_mlst);
		mat_ptr++;
	}
	return (matrix);
}
