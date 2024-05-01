/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:01:27 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 00:01:28 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_hld *a, t_hld *b)
{
	push_oth(b, a);
	ft_printf("pa\n");
}

void	pb(t_hld *a, t_hld *b)
{
	push_oth(a, b);
	ft_printf("pb\n");
}

void	ra(t_hld *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_hld *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	sa(t_hld *a)
{
	swap(a);
	ft_printf("sa\n");
}
