/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:09:55 by titan             #+#    #+#             */
/*   Updated: 2023/09/13 02:12:32 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    int	count;
	size_t	dest_ptr;
	size_t	src_ptr;

	dest_ptr = dest;
	src_ptr = src;
    count = 0;
	if (dest_ptr > src_ptr && (src_ptr + n) > dest_ptr)
	{
		while (n)
		{
			dest_ptr[n - 1] = src_ptr[n - 1];
			n--;
			return (dest);
		}
	}
	return (memcpy(dest, src, n));
}


