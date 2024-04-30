#include "pushswap.h"

int	is_sorted(t_hld *hld)
{
	t_llst	*node;
	if (hld -> size < 2)
		return (1);
	node = hld -> head;
	while(node -> next)
	{
		if (node -> val < node -> next -> val)
			node = node -> next;
		else
			return (0);
	}
	return (1);
}

int	maxBit(int n)
{
	int msb;

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

void	sep_stk(t_hld *a, t_hld *b, int shift)
{
	int		ctr;
	int		max;

	ctr = 0;
	max = a -> size;
	while (ctr < max)
	{
		if ((a -> head -> idx >> shift) & 0b1)
			ra(a);
		else
			pb(a, b);
		ctr++;
	}
}

void	join_stk(t_hld *a, t_hld *b)
{
	while (b -> head)
		pa(a, b);
}

void	rdx_srt(t_hld *a, t_hld *b)
{
	int	shift;
	int	max_shf;

	shift = 0;
	max_shf = maxBit(a -> max_idx);
	while (shift <= max_shf && !is_sorted(a))
	{
		sep_stk(a, b, shift);
		join_stk(a, b);
		shift++;
	}
}
