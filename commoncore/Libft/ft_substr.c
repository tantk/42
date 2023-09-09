/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:15 by titan             #+#    #+#             */
/*   Updated: 2023/09/09 20:07:53 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *substr(char const *s, unsigned int start, size_t len)
{
    size_t  count;
    char    *result;

    result = (char *)malloc(sizeof(char) * len);
    if (!result)
        return NULL;
    count = 0;
    while (count < len && *s)
    {
        result[count] = s[count];
        count++;
    }

}
