/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 08:15:52 by titan             #+#    #+#             */
/*   Updated: 2023/10/03 20:03:31 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 300
#endif
typedef struct s_buffer{
	char	*buf;
	size_t	buf_chkpt;
	int		buf_size;
	int		nl_idx;
	int		err;
	int		last_read;
} t_buffer;

char	*get_next_line(int fd);
char	*buffer_reduce(t_buffer *buf_obj);
void	buffer_expand(t_buffer *buf_obj);
void	buffer_adjust(t_buffer *buf_obj, char *src, size_t new_size,
		size_t copy_size);
#endif
