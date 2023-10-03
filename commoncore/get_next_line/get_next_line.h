/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 08:15:52 by titan             #+#    #+#             */
/*   Updated: 2023/10/03 10:13:34 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 300
typedef struct s_buffer{
	char	*buf;
	int		buffer_chkpt;
	int		buf_size;
	size_t	new_line_idx;
	int		init_err;
} t_buffer;

char	*get_next_line(int fd);

#endif
