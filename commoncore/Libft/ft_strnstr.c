/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:44:17 by titan             #+#    #+#             */
/*   Updated: 2023/09/16 22:22:53 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t	len)
{
	size_t	little_len;
	char	*big_ptr;

	little_len = ft_strlen(little);
	big_ptr = (char *)big;
	if (!len)
		return (NULL);
	if (!little_len)
		return (big_ptr);
	while (len >= little_len)
	{
		if (!ft_strncmp(big_ptr, little, little_len))
			return (big_ptr);
		big_ptr++;
		len--;
	}
	return (NULL);
}
