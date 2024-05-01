/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:01:49 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:10:09 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_split(char **split)
{
	char	**split_st;

	split_st = split;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(split_st);
}

void	free_hld(t_hld *hld)
{
	t_llst	*node;
	t_llst	*tmp;

	node = hld -> head;
	while (node)
	{
		tmp = node -> next;
		free(node);
		node = tmp;
	}
	free(hld);
}

void	*free_exit_hld(t_hld *hld, char **split)
{
	free_hld(hld);
	free_split(split);
	return (NULL);
}
