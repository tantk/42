/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:18:10 by titan             #+#    #+#             */
/*   Updated: 2023/09/09 16:49:58 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *str;
    str = s;
    while(n)
    {
        n--;
        *str = c;
        str++;
    }
    return s;
}
