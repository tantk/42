/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:54:24 by titan             #+#    #+#             */
/*   Updated: 2023/09/19 22:05:31 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temptr;

	while (*lst != NULL)
	{
		temptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temptr;
	}
	*lst = NULL;
}
