/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:12:57 by titan             #+#    #+#             */
/*   Updated: 2023/09/16 21:53:25 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	int				iter;
	
	if (!n)
		return (0);
	iter = n - 1;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	while (iter && *s1_ptr== *s2_ptr)
	{
		s1_ptr++;
		s2_ptr++;
		iter--;
	}
	return ((int)(*s1_ptr - *s2_ptr));
}
