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

void	free_hld(t_hld *hld)
{
	t_llst *node;
	t_llst *tmp;

	node = hld -> head;

	while (node)
	{
		tmp = node;	
		free(node);
		node =  NULL;
		node = tmp -> next;

	}
	free(hld);
	hld = NULL;
}

int	free_exit_hld(t_hld *hld, char *msg)
{
	free_hld(hld);
	ft_printf_err("Error: %s", msg);
	return (0);
}
int stk_push(t_hld *hld, int val)
{
    t_llst  *node;
    node =  (t_llst *)malloc(sizeof(t_llst));
	if (!(node && dup_check(hld,val)))
        return (free_exit_hld(hld, "Malloc fail or duplicated val"));
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

