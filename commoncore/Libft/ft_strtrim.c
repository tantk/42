/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:28:23 by titan             #+#    #+#             */
/*   Updated: 2023/09/16 15:52:52 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	result_len;

	result = ft_strdup(s1);
	while (*set)
	{
		while (*result == *set)
		{
			*result = '\0';
			result++;
		}
		result_len = ft_strlen(result);
		while (result[result_len - 1] == *set)
		{
			result[result_len - 1] = '\0';
			result_len--;
		}
		set++;
	}
	return (result);
}
