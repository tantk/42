/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:00:26 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:10:28 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_flow(t_hld *a, t_hld *b)
{
	unsigned int	size;

	size = a -> size;
	if (is_sorted(a))
		return ;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b, 0);
	else if (size == 5)
		sort_5(a, b);
	else
		rdx_srt(a, b);
}

/*
	t_llst	*node;
	node = a -> head;
	while ( node)
    {
		ft_printf("number : %d, ",node -> val);
		ft_printf("idx : %d\n",node -> rk);

		node = node -> next;
		//i++;
    }
	*/
int	main(int argc, char **argv)
{
	t_hld	*a;
	t_hld	*b;

	a = parse_args(argc, argv);
	if (!a)
		return (0);
	b = init_hld();
	if (!a || !b)
		return (0);
	sort_flow(a, b);
	free_hld(a);
	free_hld(b);
	return (1);
}
