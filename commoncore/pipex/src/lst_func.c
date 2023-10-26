/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:23:59 by titan             #+#    #+#             */
/*   Updated: 2023/10/26 17:07:48 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void pp_hdlclear(t_hld *hld)
{
	t_lst	*i;
	t_lst	*j;

	i = hld -> head;
	while (i)
	{
		j = i -> next;
		free(i -> content);
		free(i);
		i = j;
	}
	free(hld);
}

int	pp_lstadd(t_hld *hld, char const *str)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (!new_node)
		return (-1);
	new_node -> next = NULL;
	new_node -> content = (char *)str;
	if (!new_node -> content)
		return (-1);
	if (!hld -> head)
	{
		hld -> head = new_node;
		hld -> size = 0;
	}
	else
		hld -> last -> next = new_node;
	hld -> last = new_node;
	hld -> size++;
	return (1);
}

char **pp_get_content(t_hld *hld)
{
	char	**res;
	char	**res_ptr;
	t_lst	*lst;

	res = (char **)malloc((hld -> size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res_ptr = res;
	lst = hld -> head;
	while (lst)
	{
		*res_ptr = lst -> content;
		res_ptr++;
		lst = lst -> next;
	}
	res[hld->size] = NULL;
	return (res);
}


