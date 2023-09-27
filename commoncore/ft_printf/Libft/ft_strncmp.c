/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:52:58 by titan             #+#    #+#             */
/*   Updated: 2023/09/18 15:36:49 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	int				iter;

	if (!n)
		return (0);
	iter = n - 1;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	while (*s1_ptr == *s2_ptr && *s1_ptr && iter)
	{
		s1_ptr++;
		s2_ptr++;
		iter--;
	}
	return (*s1_ptr - *s2_ptr);
}
/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 == *str2 && (*str1 || *str2) && n--)
	{
		str1++;
		str2++;
	}
	if (n)
		return (*str1 - *str2);
	return (0);
}*/
