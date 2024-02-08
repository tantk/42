/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:14:48 by titan             #+#    #+#             */
/*   Updated: 2023/09/18 15:35:28 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_ptr;

	s_ptr = (char *)s;
	while (*s_ptr)
		++s_ptr;
	while ((s - 1) != s_ptr)
	{
		if (*s_ptr == (char)c)
			return (s_ptr);
		s_ptr--;
	}
	if (!c)
		return (s_ptr);
	return (NULL);
}
