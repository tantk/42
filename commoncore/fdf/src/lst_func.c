/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:53:38 by titan             #+#    #+#             */
/*   Updated: 2023/11/11 19:23:48 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_lstadd(t_mlst_hld *hld, t_3Dpoint *pt)
{
	t_mlst	*new_node;

	new_node = malloc(sizeof(t_mlst));
	if (!new_node)
		exit_error("fdf_lstadd malloc failure");
	new_node -> content = pt;
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

