# include "pushswap.h"

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

void	free_split(char **split)
{
	char **split_st;

	split_st = split;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(split_st);
}


void	free_hld(t_hld *hld)
{
	t_llst *node;
	t_llst *tmp;

	node = hld -> head;

	while (node)
	{
		tmp = node -> next;	
		free(node);
		node = tmp;
	}
	free(hld);
}

void	*free_exit_hld(t_hld *hld, char **split)
{
	free_hld(hld);
	free_split(split);
	return (NULL);
}

int stk_push(t_hld *hld, int val, int idx)
{
    t_llst  *node;
    node =  (t_llst *)malloc(sizeof(t_llst));
	if (!(node && dup_check(hld,val)))
		return (ft_err_int("duplicated digit"));
    node -> val = val;
	node -> idx = idx;
    node -> next = NULL;
    if (!hld -> head)
    {
        hld -> head = node;
        hld -> last = node;
        hld -> size = 1;
        return (1);
    }
    node -> next = hld -> head;
    hld -> head = node;
	hld -> size++;
    return (1);
}

int stk_rev_ins(t_hld *hld, int val, int idx)
{
    t_llst  *node;
    node =  (t_llst *)malloc(sizeof(t_llst));
	if (!(node && dup_check(hld,val)))
		return (ft_err_int("duplicated digit"));
    node -> val = val;
	node -> idx = idx;
    node -> next = NULL;
    if (!hld -> head)
    {
        hld -> head = node;
        hld -> last = node;
        hld -> size = 1;
        return (1);
    }
    hld -> last -> next = node;
	hld -> last = node;
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

