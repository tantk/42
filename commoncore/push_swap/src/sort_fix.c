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


