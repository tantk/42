# include "pushswap.h"

int check_bit(int check, int val)
{
    return (check | val);
}

int dup_check(t_hld *hld, int val)
{
	t_llst *node;

	node = hld -> head;
	while (node)
	{
		if (val == node -> val)
			return (0); 
		node = node -> next;
	}
	return (1);
}

int stk_push(t_hld *hld, int val)
{
    t_llst  *node;
    node =  (t_llst *)malloc(sizeof(t_llst));
	if (!(node && dup_check(hld,val)))
		//free and return 0
        return (0);
    node -> val = val;
    node -> next = NULL;
    if (!hld -> head)
    {
        hld -> head = node;
        hld -> last = node;
        hld -> size = 1;
        hld -> check = 0;
        hld -> check = check_bit(hld-> check, val);
        return (1);
    }
    node -> next = hld -> head;
    hld -> head = node;
    hld -> check = check_bit(hld-> check, val);
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
	return (1);
}

void	free_hld(t_hld *hld)
{
	t_llst *node;
	t_llst *tmp;

	node = hld -> head;

	while (node)
	{
		tmp = node;	
		node = node -> next;
		free(tmp);
	}
	free(hld);
}
