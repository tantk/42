/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:54:31 by titan             #+#    #+#             */
/*   Updated: 2023/10/07 06:31:11 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_memcpy_gnl(char *dest, const char *src, size_t n, int terminate)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (!dest || !src)
		return (NULL);
	dest_ptr = dest;
	src_ptr = src;
	if (!n)
		while (*src_ptr)
			*dest_ptr++ = *src_ptr++;
	else
		while (n--)
			*dest_ptr++ = *src_ptr++;
	if (terminate)
	{
		*dest_ptr = '\0';
		return (dest);
	}
	else
		return (dest_ptr);
}

// return 1 if fails, return 0 if successful
int	ft_lstadd(t_storage *storage, char *str, int len)
{
	t_lst	*node;
	char	*content;

	content = (char *)malloc(sizeof(char) * (len + 1));
	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node || !content)
		return (1);
	ft_memcpy_gnl(content, str, len, 1);
	node -> content = content;
	node -> next = NULL;
	if (!storage -> head)
		storage -> head = node;
	else
		storage -> last -> next = node;
	storage -> last_len = len;
	storage -> content_len += len;
	storage -> last = node;
	return (0);
}

void	ft_lstclear(t_storage *storage)
{
	t_lst	*i;
	t_lst	*j;

	i = storage -> head;
	while (i)
	{
		j = i -> next;
		free(i -> content);
		free(i);
		i = j;
	}
	storage -> last_len = 0;
	storage -> content_len = 0;
	storage -> head = NULL;
	storage -> last = NULL;
}

char	*extract_line(t_storage *storage, int nl_idx)
{
	int		line_len;
	char	*line;
	char	*line_ptr;
	t_lst	*i;

	if (!storage -> head)
		return (NULL);
	line_len = storage -> content_len - storage -> last_len + nl_idx + 1;
	line = (char *)malloc((line_len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line_ptr = line;
	i = storage -> head;
	while (i && i != storage -> last)
	{
		line_ptr = ft_memcpy_gnl(line_ptr, i->content, 0, 0);
		i = i -> next;
	}
	line_ptr = ft_memcpy_gnl(line_ptr, i -> content, nl_idx + 1, 1);
	return (line);
}

void	store_leftover(t_storage *storage, int nl_idx)
{
	int		leftover_len;
	char	*leftover;

	leftover_len = storage -> last_len - (nl_idx + 1);
	leftover = (char *)malloc(sizeof(char) + (leftover_len + 1));
	if (!leftover)
	{
		storage -> err = 1;
		return ;
	}
	ft_memcpy_gnl(leftover, storage -> last -> content + (nl_idx + 1), 0, 1);
	ft_lstclear(storage);
	ft_lstadd(storage, leftover, leftover_len);
	free(leftover);
}
