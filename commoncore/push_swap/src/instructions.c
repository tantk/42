# include "pushswap.h"

int	push_oth(t_hld *a, t_hld *b)
{
	t_llst	*tmp;

	tmp = a -> head;
	stk_pop(a);
	stk_push(b, tmp -> val, tmp -> idx);
	free(tmp);
	return (1);
}

int	rotate(t_hld *hld)
{
	t_llst *tmp;

	if (hld -> size == 1)
		return (0);
	tmp = hld -> head;
	hld -> head = tmp -> next;
	hld -> last -> next = tmp;
	hld -> last = tmp;
	hld -> last -> next = NULL;
	return (1);
}
