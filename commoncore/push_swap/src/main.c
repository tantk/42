#include "pushswap.h"

int	main(int argc, char **argv)
{
	//int		i;
	t_hld	*hld;
	t_llst	*node;

	//i = 1;
	hld = (t_hld *) malloc(sizeof(t_hld));
	hld = parse_args(argc, argv);
	if (!hld)
		return (0);
	node = hld -> head;
	//rotate(hld);
	node = hld -> head;
	while ( node)
    {
		ft_printf("number : %d, ",node -> val);
		ft_printf("idx : %d\n",node -> idx);

		node = node -> next;
		//i++;
    }
	return (1);
}
