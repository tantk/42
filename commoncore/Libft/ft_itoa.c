/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:20:47 by titan             #+#    #+#             */
/*   Updated: 2023/09/19 06:22:52 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int num_len(long n)
{
	if (n < 0)
		return (1 + num_len(-n));
	else if (n > 9)
		return (1 + num_len(n / 10));
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	long	n_long;

	n_long = (long) n;
	len = num_len(n_long);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		n_long = -n_long;
	result[len] = '\0';
	while(len)
	{
		result[len-- - 1] =  n_long % 10 + '0';
		n_long = n_long / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
