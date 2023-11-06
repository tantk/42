/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:44:17 by titan             #+#    #+#             */
/*   Updated: 2023/09/18 22:38:51 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t	len)
{
	size_t	little_len;
	char	*big_ptr;

	little_len = ft_strlen(little);
	big_ptr = (char *)big;
	if (!little_len)
		return (big_ptr);
	if (len <= 0 || !ft_strlen(big))
		return (NULL);
	while (len >= little_len && *big_ptr)
	{
		if (!ft_strncmp(big_ptr, little, little_len))
			return (big_ptr);
		big_ptr++;
		len--;
	}
	return (NULL);
}
