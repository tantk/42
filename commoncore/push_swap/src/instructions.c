# include "pushswap.h"

int	push_oth(t_hld *a, t_hld *b)
{
	t_llst	*tmp;

	tmp = a -> head;
	stk_pop(a);
	stk_push(b, tmp -> val);
	free(tmp);
	return (1);
}

int	rotate(t_hld *hld)
{
	t_llst *tmp;

	tmp = hld -> head;
	stk_pop(hld);
	if (!hld -> last)
	{
		hld -> last -> next = tmp;
		hld -> head = tmp -> next;
	}
	else
	{
		hld -> head = tmp;
		hld -> last = tmp;
	}
	return (1);
}
