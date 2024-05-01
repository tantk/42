/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:02:07 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:13:07 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_limit(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	check_num(char *num)
{
	if (*num == '-')
		num++;
	while (*num)
	{
		if (ft_isdigit((int)*num))
			num++;
		else
			return (0);
	}
	return (1);
}

int	check_num_arr(char **str)
{
	while (*str)
	{
		if (check_num(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

t_llst	*first_node(t_hld *hld)
{
	t_llst	*node;

	node = hld -> head;
	while (node)
	{
		if (node -> rk == -1)
			return (node);
		node = node -> next;
	}
	return (NULL);
}

t_llst	*min_val(t_hld *hld)
{
	t_llst	*node;
	t_llst	*min_node;

	node = hld -> head;
	min_node = first_node(hld);
	while (node)
	{
		if (min_node -> val > node -> val && node -> rk == -1)
			min_node = node;
		node = node -> next;
	}
	return (min_node);
}
