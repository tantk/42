# include "push_swap.h"

int	push_b(t_hld *a, t_hld *b)
{
	t_llst	*tmp;

	tmp = a -> head;
	stk_pop(a);
	stk_push(b, tmp -> val);
	free(tmp);
	return (1);
}

int	push_a(t_hld *a, t_hld *b)
{
	t_llst	*tmp;

	tmp = b -> head;
	stk_pop(b);
	stk_push(a, tmp -> val);
	free(tmp);
	return (1);
}

int	rotate_a(t_hld *a)
{
	t_llst *tmp;

	tmp = a -> head;
	stk_pop(a);
	if (!hld -> last)
	{
		hld -> last -> next = tmp;
		hld -> head = tmp -> head -> next;
	}
	else
	{
		hld -> head = tmp;
		hld -> last = tmp;
	}
	return (1);
}

int	rotate_b(t_hld *b)
{
	t_llst *tmp;

	tmp = b -> head;
	stk_pop(b);
	if (!hld -> last)
	{
		hld -> last -> next = tmp;
		hld -> head = tmp -> head -> next;
	}
	else
	{
		hld -> head = tmp;
		hld -> last = tmp;
	}
	return (1);
}
