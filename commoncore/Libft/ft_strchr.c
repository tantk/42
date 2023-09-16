/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:43:11 by titan             #+#    #+#             */
/*   Updated: 2023/09/16 19:04:14 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src)
	{
		if (*src == (char)c)
			return ((char *)src);
		src++;
	}
	if (!c)
		return ((char *)src);
	return (NULL);
}
