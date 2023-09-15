/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:13:20 by titan             #+#    #+#             */
/*   Updated: 2023/09/15 19:13:57 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    size_t  s_len;
    char    *s_ptr;

    s_len = ft_strlen(s);
    s_ptr = (char *)malloc(s_len * sizeof(char));
    if (!s_ptr)
        return (NULL);
    s_ptr = ft_memcpy(s_ptr, s, s_len);
    if (s_ptr[s_len - 1] != '\0')
        s_ptr[s_len - 1] = '\0';
    return (s_ptr);
}

