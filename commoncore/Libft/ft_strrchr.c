/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:14:48 by titan             #+#    #+#             */
/*   Updated: 2023/09/13 20:31:51 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    size_t  s_len;
    char    *s_ptr;

    s_ptr = (char *)s;
    s_len = ft_strlen(s);
    while(s_len)
    {
        if ((char)s_ptr[s_len - 1] == (char)c)
            return (s_ptr);
        s_len--;
    }
    return (NULL);
}
