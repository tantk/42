/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:58:48 by titan             #+#    #+#             */
/*   Updated: 2023/09/13 16:33:26 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t len_src;

    len_src = ft_strlen(src);
    if (len_src + 1 <= size)
        ft_memcpy(dst, src, len_src + 1);
    else if (size > 0)
    {
        ft_memcpy(dst, src, size - 1);
        dst[size - 1] = '\0';
    }
    return (len_src);
}
