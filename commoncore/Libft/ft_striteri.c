/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:41:42 by titan             #+#    #+#             */
/*   Updated: 2023/09/09 18:55:03 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    size_t  count;
    size_t  len;

    len = ft_strlen((const char)*s);
    count = 0;

    while(count < len)
    {
        f((unsigned int)count, &s[count]);
        count++;
    }
}
