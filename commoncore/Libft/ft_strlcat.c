/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:33:51 by titan             #+#    #+#             */
/*   Updated: 2023/09/16 18:46:53 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	n;
	char	*dst_ptr;
	char	*src_ptr;

	d_len = ft_strlen(dst);
	dst_ptr = dst + d_len;
	src_ptr = (char *)src;
	if (d_len > size)
		d_len = size;
	n = size - d_len;
	if (!n)
		return (d_len + ft_strlen(src));
	while (*src_ptr)
	{
		if (n > 1)
		{
			*dst_ptr++ = *src_ptr;
			n--;
		}
		src_ptr++;
	}
	*dst_ptr = '\0';
	return (d_len + (src_ptr - src));
}
