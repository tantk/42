/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:54:31 by titan             #+#    #+#             */
/*   Updated: 2023/10/05 16:12:45 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strcpy_gnl(char *dest, const char *src)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (!dest || !src)
		return (0);
	dest_ptr = dest;
	src_ptr = src;
	while (*src)
		*dest_ptr++ = *src_ptr++;
	*dest_ptr = '\0';
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

// return 1 if fails, return 0 if successful
// use parameter len of 0 if we want to assume BUFFER_SIZE
int	ft_lstnew(t_storage *storage, char *str, int len)
{
	t_lst	*node;
	char	*content;

	content = (char *)malloc(sizeof(char) * (len + 1));
	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node || !content)
		return (1);
	ft_memcpy_gnl(content, str, len);
	node -> content = content;
	node -> next = NULL;
	if (!storage -> head)
	{
		storage -> head = node;
		storage -> head_len = len;
	}
	else
		storage -> last -> next = node;
	storage -> size++;
	storage -> last = node;
	storage -> last_len = node;
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
	storage -> size = 0;
	storage -> head_len = 0;
	storage -> head = NULL;
	storage -> last = NULL;
}

char	*extract_line(t_storage *storage, int nl_idx)
{
	int		line_len;
	char	*line;
	char	*line_ptr;
	t_lst	*i;

	if (storage -> size > 2)
		line_len = (storage -> size - 2) * BUFFER_SIZE + (nl_idx + 1);
	else if (storage -> size == 2)
		line_len = storage -> head_len + storage -> last_len;
	else
		line_len = storage -> head_len;
	line = (char *)malloc((line_len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line_ptr = line;
	i = storage -> head;
	while (i && storage -> last != i)
	{
		ft_memcpy_gnl(line_ptr, i->content, BUFFER_SIZE);
		line_ptr += BUFFER_SIZE;
		i = i -> next;
	}
	ft_memcpy_gnl(line_ptr, i -> content, (nl_idx + 1));
	return (line);
}

void	store_leftover(t_storage *storage, )
