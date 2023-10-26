/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:48 by titan             #+#    #+#             */
/*   Updated: 2023/10/26 06:30:49 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//24 bytes
typedef struct s_lst_holder{
	t_lst			*head;
	t_lst			*last;
	unsigned int	size;
} t_hld;


/*

   file fd
   process id
   pipe
   fd
	queue number
	
	

 */

/*
parse cmd 
 
  */


#endif
