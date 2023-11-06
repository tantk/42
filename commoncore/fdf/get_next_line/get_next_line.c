/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:17:01 by titan             #+#    #+#             */
/*   Updated: 2023/10/07 07:08:47 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_find_nl(const char *src)
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

static int	ret_cond(t_storage *storage, int nl_idx, int rd_bytes)
{
	if (rd_bytes == 0 && storage -> last != NULL)
		return (storage -> last_len - 1);
	if (rd_bytes == -1)
		return (-1);
	if (rd_bytes < BUFFER_SIZE && nl_idx != -1)
		return (nl_idx);
	if (rd_bytes < BUFFER_SIZE)
		return (rd_bytes - 1);
	return (nl_idx);
}

static int	read_till_nl(t_storage *storage, int fd)
{
	int		nl_idx;
	int		rd_bytes;
	char	*buf;

	nl_idx = -1;
	if (storage -> last)
		nl_idx = ft_find_nl(storage -> last -> content);
	if (nl_idx != -1)
		return (nl_idx);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	rd_bytes = read(fd, buf, BUFFER_SIZE);
	while (rd_bytes > 0)
	{
		buf[rd_bytes] = '\0';
		ft_lstadd(storage, buf, rd_bytes);
		nl_idx = ft_find_nl(storage -> last -> content);
		if (rd_bytes < BUFFER_SIZE || nl_idx >= 0)
			break ;
		rd_bytes = read(fd, buf, BUFFER_SIZE);
	}
	storage -> last_read = rd_bytes;
	free(buf);
	return (ret_cond(storage, nl_idx, rd_bytes));
}

char	*get_next_line(int fd)
{
	static t_storage	storage = {0, 0, 0, -1, NULL, NULL};
	int					nl_idx;
	char				*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	nl_idx = read_till_nl(&storage, fd);
	if (nl_idx == -1)
	{
		ft_lstclear(&storage);
		return (NULL);
	}
	line = extract_line(&storage, nl_idx);
	if (!line)
		return (NULL);
	if ((nl_idx + 1) < storage.last_read)
		store_leftover(&storage, nl_idx);
	else
		ft_lstclear(&storage);
	if (storage.err)
		return (NULL);
	return (line);
}
