/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:44:17 by titan             #+#    #+#             */
/*   Updated: 2023/09/14 20:14:30 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char    *ft_strnstr(const char  *big, const char *little, size_t len)
{
    int little_len;
    char *big_ptr;

    little_len = ft_strlen(little);
    big_ptr = (char *)big;
    if (!little_len)
        return big_ptr;
    while(len)
    {
        if (!ft_strncmp(big, little, little_len))
            return big_ptr;
        big_ptr++;
    }
    return (NULL);
}

