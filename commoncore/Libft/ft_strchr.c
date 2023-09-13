/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:43:11 by titan             #+#    #+#             */
/*   Updated: 2023/09/13 18:54:52 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    char *s_ptr;

    s_ptr = (char *)s;
	while (1)
	{
        if (*s_ptr == (char)c)
            return (s_ptr);
        if ((char)*s_ptr == '\0')
            return (NULL);
        s_ptr++;
    }
}
