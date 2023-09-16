/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:22:02 by titan             #+#    #+#             */
/*   Updated: 2023/09/16 15:12:38 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	uc_c;

	s_ptr = (unsigned char *)s;
	uc_c = (unsigned char) c;
	while (n)
	{
		if (*s_ptr == uc_c)
			return (s_ptr);
		n--;
		s_ptr++;
	}
	return (NULL);
}
