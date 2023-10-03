/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:54:31 by titan             #+#    #+#             */
/*   Updated: 2023/10/03 20:32:48 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (!dest && !src)
		return (0);
	dest_ptr = dest;
	src_ptr = src;
	while (n)
	{
		*dest_ptr++ = *src_ptr++;
		n--;
	}
	return (dest);
}

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n)
	{
		n--;
		*str = c;
		str++;
	}
	return (s);
}

void	buffer_adjust(t_buffer *buf_obj, char *src, size_t new_size,
		size_t copy_size)
{
	char	*new_buffer;

	new_buffer = (char *)malloc((new_size + 1) * sizeof(char));
	if (!new_buffer)
	{
		buf_obj -> err = 1;
		return ;
	}
	ft_memcpy(new_buffer, src, copy_size);
	new_buffer[new_size] = '\0';
	ft_memset(buf_obj -> buf, 0, buf_obj -> buf_size);
	free(buf_obj -> buf);
	buf_obj -> buf = new_buffer;
	buf_obj -> buf_size = new_size;
}

char	*buffer_reduce(t_buffer *buf_obj)
{
	char	*line;
	size_t	new_size;

	new_size = buf_obj -> buf_size - buf_obj -> nl_idx - 1;
	if (!new_size)
	{
		buf_obj -> buf_size = 0;
		return (buf_obj -> buf);
	}
	line = (char *)malloc((buf_obj -> nl_idx + 2) * sizeof(char *));
	if (!line)
		return (NULL);
	buffer_adjust(buf_obj, buf_obj -> buf + buf_obj -> nl_idx + 1,
		new_size, new_size);
	line = ft_memcpy(line, buf_obj -> buf, buf_obj -> nl_idx + 1);
	line[buf_obj -> nl_idx + 1] = '\0';
	buf_obj -> buf_chkpt = 0;
	return (line);
}

void	buffer_expand(t_buffer *buf_obj)
{
	int		new_size;

	new_size = buf_obj -> buf_size + BUFFER_SIZE;
	buffer_adjust(buf_obj, buf_obj-> buf, new_size, buf_obj -> buf_size);
	if (buf_obj -> err)
		return ;
	buf_obj -> buf_chkpt = buf_obj -> buf_size;
}
