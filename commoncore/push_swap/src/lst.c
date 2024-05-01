/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:01:42 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:08:54 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	dup_check(t_hld *hld, int val)
{
	t_llst	*node;

	node = hld -> head;
	while (node)
	{
		if (val == node -> val)
			return (0);
		node = node -> next;
	}
	return (1);
}

int	stk_push(t_hld *hld, int val, int rk)
{
	t_llst	*node;

	if (!dup_check(hld, val))
		return (ft_err_int("Error\n"));
	node = (t_llst *)malloc(sizeof(t_llst));
	if (!node)
		return (ft_err_int("Error\n"));
	node -> val = val;
	node -> rk = rk;
	node -> next = NULL;
	if (!hld -> head)
	{
		hld -> head = node;
		hld -> last = node;
		hld -> size = 1;
		return (1);
	}
	node -> next = hld -> head;
	hld -> head = node;
	hld -> size++;
	return (1);
}

int	stk_rev_ins(t_hld *hld, int val, int rk)
{
	t_llst	*node;

	if (!dup_check(hld, val))
		return (ft_err_int("Error\n"));
	node = (t_llst *)malloc(sizeof(t_llst));
	if (!node)
		return (ft_err_int("Error\n"));
	node -> val = val;
	node -> rk = rk;
	node -> next = NULL;
	if (!hld -> head)
	{
		hld -> head = node;
		hld -> last = node;
		hld -> size = 1;
		return (1);
	}
	hld -> last -> next = node;
	hld -> last = node;
	hld -> size++;
	return (1);
}

int	stk_pop(t_hld *hld)
{
	t_llst	*tmp;

	tmp = hld -> head;
	hld->head = hld -> head -> next;
	if (!hld -> head)
		hld -> last = NULL;
	free(tmp);
	hld -> size --;
	return (1);
}
