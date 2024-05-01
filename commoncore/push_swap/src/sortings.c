/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:02:19 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:16:10 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_hld *hld)
{
	t_llst	*node;

	if (hld -> size < 2)
		return (1);
	node = hld -> head;
	while (node -> next)
	{
		if (node -> val < node -> next -> val)
			node = node -> next;
		else
			return (0);
	}
	return (1);
}

static int	max_bit(int n)
{
	int	msb;

	msb = 0;
	if (n == 0)
		return (0);
	n = n / 2;
	while (n != 0)
	{
		n = n / 2;
		msb++;
	}
	return (msb);
}

static void	sep_stk(t_hld *a, t_hld *b, int shift)
{
	int		ctr;
	int		max;

	ctr = 0;
	max = a -> size;
	while (ctr < max)
	{
		if ((a -> head -> rk >> shift) & 0b1)
			ra(a);
		else
			pb(a, b);
		ctr++;
	}
}

static void	join_stk(t_hld *a, t_hld *b)
{
	while (b -> head)
		pa(a, b);
}

void	rdx_srt(t_hld *a, t_hld *b)
{
	int	shift;
	int	max_shf;

	shift = 0;
	max_shf = max_bit(a -> max_rk);
	while (shift <= max_shf && !is_sorted(a))
	{
		sep_stk(a, b, shift);
		join_stk(a, b);
		shift++;
	}
}
