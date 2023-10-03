/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:17:01 by titan             #+#    #+#             */
/*   Updated: 2023/10/03 20:00:53 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_find_nl(const char *src)
{
	int	idx;

	idx = 0;
	while (*src)
	{
		if (*src == '\n')
			return (idx);
		idx++;
		src++;
	}
	return (-1);
}

t_buffer	init_buffer(int buf_size)
{
	t_buffer	buf_obj;

	if (buf_size <= 0)
	{
		buf_obj.err = 1;
		return (buf_obj);
	}
	buf_obj.buf = (char *)malloc(sizeof(char) * (buf_size + 1));
	if (!buf_obj.buf)
	{
		buf_obj.err = 1;
		return (buf_obj);
	}
	buf_obj.buf[buf_size] = '\0';
	buf_obj.buf_size = buf_size;
	return (buf_obj);
}

// read returns number of bytes read , 0 indicates eof, -1 on error
void	read_till_nl(int fd, t_buffer *buf_obj)
{
	int	rd_res;
	char *buf_ptr;

	rd_res = 0;
	while (buf_obj -> nl_idx == -1)
	{
		buf_ptr = buf_obj -> buf + buf_obj -> buf_chkpt;
		rd_res = read(fd, buf_ptr, BUFFER_SIZE);
		if (rd_res == -1 || !rd_res)
		{
			buf_obj -> err = 1;
			return;
		}
		else if (0 < rd_res && rd_res < BUFFER_SIZE )
		{
			buf_obj -> last_read = buf_obj -> buf_chkpt + rd_res;
			return;
		}
		buf_ptr[BUFFER_SIZE] = '\0';
		buf_obj -> nl_idx = ft_find_nl(buf_ptr);
		if (buf_obj -> nl_idx >= 0)
			buf_obj -> nl_idx += buf_obj -> buf_chkpt;
		else
			buffer_expand(buf_obj);
	}
}

char	*get_next_line(int fd)
{
	static	t_buffer	buf_obj = {NULL, 0, 0, -1, 0, 0};

	if (!buf_obj.buf_size)
		buf_obj = init_buffer(BUFFER_SIZE);
	while (!buf_obj.last_read || !buf_obj.err)
	{
		read_till_nl(fd, &buf_obj);
		if (buf_obj.nl_idx >= 0)
			return (buffer_reduce(&buf_obj));
	}
	if (buf_obj.last_read)
	{
		buffer_adjust(&buf_obj, buf_obj.buf,
				buf_obj.last_read,buf_obj.last_read);
		if (!buf_obj.err)
			return (buf_obj.buf);
	}
	return(NULL);
}
