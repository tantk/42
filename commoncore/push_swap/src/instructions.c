# include "pushswap.h"

t_llst	*find_node(t_hld *hld, int val)
{
	t_llst	*node;

	node = hld -> head;
	while (node)
	{
		if (node -> rk == val)
			return (node);
		node = node -> next;
	}
	return (NULL);
}

t_llst	*find_slst(t_hld *hld)
{
	t_llst *node;

	node = hld -> head;
	
	while (node)
	{
		if (node -> next)
			if (!node -> next -> next)
				return (node);
		node = node -> next;
	}
	return (NULL);
}

int	push_oth(t_hld *a, t_hld *b)
{
	int	tmp_rk;
	int tmp_val;

	tmp_rk = a -> head -> rk;
	tmp_val = a -> head -> val;
	stk_pop(a);
	stk_push(b, tmp_val, tmp_rk);
	return (1);
}

int	rotate(t_hld *hld)
{
	t_llst *tmp;

	if (hld -> size == 1)
		return (1);
	tmp = hld -> head;
	hld -> head = tmp -> next;
	hld -> last -> next = tmp;
	hld -> last = tmp;
	hld -> last -> next = NULL;
	return (1);
}

int rev_rotate(t_hld *hld)
{
	t_llst	*new_last;
	t_llst	*new_first;

	if (hld -> size == 1)
		return (1);
	new_last = find_slst(hld);
	new_first = hld -> last;
	new_last -> next = NULL;
	new_first -> next = hld -> head;
	hld -> head = new_first;
	hld -> last = new_last;
	return (1);
}

int	swap(t_hld *hld)
{
	int	tmp_val;
	int	tmp_rk;

	if (hld -> size < 2)
		return (0);
	tmp_val = hld -> head -> val;
	tmp_rk = hld -> head -> rk;
	hld -> head -> val = hld -> head -> next -> val;
	hld -> head -> rk = hld -> head -> next -> rk;
	hld -> head -> next -> val = tmp_val;
	hld -> head -> next -> rk = tmp_rk;
	return (1);
}

void	pa(t_hld *a, t_hld *b)
{
	push_oth(b, a);
	ft_printf("pa\n");
}

void	pb(t_hld *a, t_hld *b)
{
	push_oth(a, b);
	ft_printf("pb\n");
}

void	ra(t_hld *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_hld *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	sa(t_hld *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	rra(t_hld *a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}
