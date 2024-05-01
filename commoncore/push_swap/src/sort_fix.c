/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:02:13 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:14:23 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_idx(t_hld *hld, int val)
{
	t_llst	*node;
	int		idx;

	idx = 0;
	node = hld -> head;
	while (node)
	{
		if (node -> rk == val)
			return (idx);
		idx++;
		node = node -> next;
	}
	return (-1);
}

void	sort_2(t_hld *hld)
{
	if (hld -> head -> rk > hld -> head -> next -> rk)
		sa(hld);
}

/*
[1, 2, 3] - no swaps
[1, 3, 2] - sa -> [3, 1, 2] ra -> [1, 2, 3]
[2, 1, 3] - sa -> [1, 2, 3]
[2, 3, 1] - rra -> [1, 2, 3]
[3, 1, 2] - ra -> [1, 2, 3]
[3, 2, 1] - sa -> [2, 3, 1] rra -> [1, 2, 3]*/

void	sort_3(t_hld *hld)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(hld))
		return ;
	a = hld -> head -> rk;
	b = hld -> head -> next -> rk;
	c = hld -> head -> next -> next -> rk;
	if (a < c && c < b)
	{
		sa(hld);
		ra(hld);
	}
	else if (b < a && a < c)
		sa(hld);
	else if (c < a && a < b)
		rra(hld);
	else if (b < c && c < a)
		ra(hld);
	else if (c < b && b < a)
	{
		sa(hld);
		rra(hld);
	}
}

/*
[x, 0 , x , x] - ra -> [0, x, x, x]
[x, x, 0, x] - ra ra -> [0, x, x, x]
[x, x, x, 0] - rra -> [0, x, x, x]
*/
void	sort_4(t_hld *a, t_hld *b, int find)
{
	int	idx;

	if (is_sorted(a))
		return ;
	idx = find_idx(a, find);
	if (idx == 1)
		ra(a);
	else if (idx == 2)
	{
		ra(a);
		ra(a);
	}
	else if (idx == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_hld *a, t_hld *b)
{
	int	idx;

	idx = find_idx(a, 0);
	if (idx == 1)
		ra(a);
	else if (idx == 2)
	{
		ra(a);
		ra(a);
	}
	else if (idx == 3)
	{
		rra(a);
		rra(a);
	}
	else if (idx == 4)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_4(a, b, 1);
	pa(a, b);
}
