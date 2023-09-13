/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:33:51 by titan             #+#    #+#             */
/*   Updated: 2023/09/13 18:00:31 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  d_len;
    size_t  n;

    d_len = ft_strlen(dst);
    if (d_len > size)
        d_len = size;
    n = size - d_len;
    if (!n)
        return (d_len + ft_strlen(src));
    while (*src)
    {
        if (n > 1)
        {
            *dst++ = *src++;
            n--;
        }
    }
    *dst = '\0';
    return (d_len + ft_strlen(src));
}
