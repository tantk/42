#include "pushswap.h"

int	main(int argc, char **argv)
{
	//int		i;
	t_hld	*a;
	t_hld 	*b;

	//i = 1;
	a = parse_args(argc, argv);
	b = empty_stk();
	if (!a || !b)
		return (0);
	rdx_srt(a, b);
	/*
	t_llst	*node;
	node = a -> head;
	while ( node)
    {
		ft_printf("number : %d, ",node -> val);
		ft_printf("idx : %d\n",node -> idx);

		node = node -> next;
		//i++;
    }*/
	return (1);
}
