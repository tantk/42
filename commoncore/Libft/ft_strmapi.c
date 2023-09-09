/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:24:00 by titan             #+#    #+#             */
/*   Updated: 2023/09/09 18:34:53 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
s -> string to iterate
f -> function to apply to each character

return a string after application of f
return NULL if allocation fails
 */

char    *ft_strmapi(char const *s, char(*f)(unsigned int,char))
{
    size_t  len;
    size_t  count;
    char    *result;
    count = 0;
    len = ft_strlen(s);
    result = (char *)malloc(count * sizeof(char));
    if (!result)
        return NULL;
    while (count < len)
    {
        result[count] = f((unsigned int)count, s[count]);
        count++;
    }
    return result;
}
