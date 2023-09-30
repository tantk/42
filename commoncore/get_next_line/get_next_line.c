/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:17:01 by titan             #+#    #+#             */
/*   Updated: 2023/09/30 15:53:36 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*res;
	static char		*buf = NULL;
	int	read_count;
	//check file exists // fd errors
	//check buffer size cannot be 0
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//read void new line function -> fd , address of buf , it modifies buff
	//
	read_count = read(fd, buf, BUFFER_SIZE);
	if (read_count < 0)
		//error handling
	//find newline and split 
	//before newline store as result to be returned
	//the after part have to be part of the result to be returned later. <- parses b4 new line and after newline, one of the parameter is buff
	//
	//while loop condition to continue getting content from the file. read returns 0 means end of file.
	//

	return(res);
}
