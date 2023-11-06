/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:09:55 by titan             #+#    #+#             */
/*   Updated: 2023/09/18 15:15:08 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest_ptr > src_ptr && (src_ptr + n) > dest_ptr)
	{
		while (n)
		{
			dest_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
