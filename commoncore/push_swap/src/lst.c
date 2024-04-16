# include "pushswap.h"

int check_bit(int check, int val)
{
    return (check | val);
}

int stk_add(t_hld *hld, int val)
{
    t_llst  *node;
    
    node =  (t_llst *)malloc(sizeof(t_llst));
    if (!node)
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
    return (1);
}


