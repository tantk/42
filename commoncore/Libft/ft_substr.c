/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:15 by titan             #+#    #+#             */
/*   Updated: 2023/09/15 17:32:45 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  count;
    char    *result;

    result = (char *)malloc(sizeof(char) * (len + 1));
    if (!result)
        return NULL;
    count = 0;
    while (count < len && s[count + start])
    {
        result[count] = s[count + start];
        count++;
    }
    result[count] = '\0';
    return (result);
}
