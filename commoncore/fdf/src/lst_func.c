/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:53:38 by titan             #+#    #+#             */
/*   Updated: 2023/11/11 22:14:37 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_3Dpoint	*create_empty_pt()
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

