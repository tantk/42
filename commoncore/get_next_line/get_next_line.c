/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:17:01 by titan             #+#    #+#             */
/*   Updated: 2023/10/03 10:14:00 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


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

char	*get_next_line(int fd)
{
	static	t_buffer	buf_obj = {NULL, 0, 0, 0, 0};

	if (!buf_obj.buf_size)
		buf_obj = init_buffer(BUFFER_SIZE);
	if (buf_obj.err)
		return (NULL);
	//check file exists // fd errors
	//check buffer size cannot be 0
	//read void new line function -> fd , address of buf , it modifies buff
	read_count = read(fd, buf, BUFFER_SIZE);
	//if (read_count < 0)
		//error handling
	//find newline and split 
	//before newline store as result to be returned
	//the after part have to be part of the result to be returned later. <- parses b4 new line and after newline, one of the parameter is buff
	//
	//while loop condition to continue getting content from the file. read returns 0 means end of file.
	//

	return(buf);
}
