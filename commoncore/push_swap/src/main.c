#include "pushswap.h"

int	main(int argc, char **argv)
{
    int i;
    t_hld   *hld;
    t_llst  *node;

   i = 1; 
	hld =(t_hld *) malloc(sizeof(t_hld));    
    hld = parse_args(argc, argv);
	if (!hld)
		return (0);
	node = hld -> head;
	//rotate(hld);
    while (i < argc)
    {
        ft_printf("number : %d\n",node -> val);
        node = node -> next;
        i++;
    }
    ft_printf("check: %d\n", hld -> check);
	return (1);
}
