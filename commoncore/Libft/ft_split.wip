/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:55:19 by titan             #+#    #+#             */
/*   Updated: 2023/09/15 22:38:07 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t word_count(char const *s, char c)
{
    size_t  words;
    char    *s_ptr;

    s_ptr = (char *)s;
    words = 0;
    while (*s_ptr)
    {
        if (*s_ptr == c)
        {
            while(*s_ptr == c)
                s_ptr++;
        }
        else
        {
            while(*s_ptr != c)
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
	free(result_ptr);
	return (NULL);
}

static char *ft_trim_front(char *s1, char c)
{
    while (*s1 == c)
        s1++;
    return (s1);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    char    **result_ptr;
    char    *s_ptr;
    char    *match;

    s_ptr = (char *) s;
    result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
    if (!result || !s)
        return NULL;
    result_ptr = result;
    s_ptr = ft_strtrim(s, &c);
    while(*s_ptr)
    {
        match = ft_strchr(s_ptr, (int)c);
        if (!match)
        {
            *result_ptr++ = s_ptr;
            break;
        }
        *result_ptr++ = ft_substr(s_ptr, 0, match - s_ptr);
        if (!*(result_ptr - 1))
            return ft_free_on_failure(result_ptr, result);
        s_ptr = ft_trim_front(s_ptr, c) + 1;
    }
    *result_ptr = NULL;
    return result;
}
