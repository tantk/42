# include "pushswap.h"

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
		return (0);
	tmp = hld -> head;
	hld -> head = tmp -> next;
	hld -> last -> next = tmp;
	hld -> last = tmp;
	hld -> last -> next = NULL;
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
