# include "pushswap.h"

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
        return (1);
    }
    node -> next = hld -> head;
    hld -> head = node;
    return (1);
}
