#include "pushswap.h"


int	main(int argc, char **argv)
{
    int i;
    t_hld   *hld;
    t_llst  *node;

    hld =(t_hld *) malloc(sizeof(t_hld));    
    i = 1;
    while(i < argc)
    {
        stk_add(hld, ft_atoi(argv[i]));
        i++;
    }
    i = 1;
    node = hld -> head;
    while (i < argc)
    {
        ft_printf("number : %d\n",node -> val);
        node = node -> next;
        i++;
    }
	return (1);
}
