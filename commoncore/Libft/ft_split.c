/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:55:19 by titan             #+#    #+#             */
/*   Updated: 2023/09/19 13:09:46 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	words;
	char	*s_ptr;

	s_ptr = (char *)s;
	words = 0;
	while (*s_ptr)
	{
		if (*s_ptr == c)
		{
			while (*s_ptr == c)
				s_ptr++;
		}
		else
		{
			while (*s_ptr != c && *s_ptr)
				s_ptr++;
			words++;
		}
	}
	return (words);
}

static char	**ft_free_on_failure(char **result_ptr, char **result)
{
	while (*result_ptr != *result)
	{
		free(*result_ptr);
		result_ptr--;
	}
	free(*result_ptr);
	free(result_ptr);
	return (NULL);
}

static int	find_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	if (count > 0)
		return (count);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	**result_ptr;
	int		len;

	result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result || !s)
		return (NULL);
	result_ptr = result;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		len = find_len(s, c);
		if (!len)
			break ;
		*result_ptr = ft_substr(s, 0, len);
		if (!*result_ptr)
			return (ft_free_on_failure(result_ptr, result));
		result_ptr++;
		s += len;
	}
	*result_ptr = NULL;
	return (result);
}
