/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:48 by titan             #+#    #+#             */
/*   Updated: 2023/10/27 05:14:21 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <string.h>
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

typedef struct s_proc{
	int		prd_pipe[2];
	int		pwr_pipe[2];
	int		pid;
	t_hld	*cmd_holder;
	char	*path;
} t_proc;

t_hld	*pp_parse_cmd(const char *cmd);
void pp_hdlclear(t_hld *hld);
int pp_lstadd(t_hld *hld, char const *str);
char **pp_get_content(t_hld *hld);

int	redir_io(char *filepath, int fd1, int fd2, int rwx);
int	redir_fd(int fd1, int fd2);
char	*find_exec(char *prog_name, char *path_var);
int	nil_prog_err(char *prog_name);
int	ret_errmsg(const char *msg);
char *ret_errmsg_char(const char *msg);
int	ret_err_cust_msg(const char *msg, int errorcode);
void	exit_failure();
/*

   file fd
   process id
   pipe
   fd
   queue number = argv
	
	

 */

/*
parse cmd 
 
  */

#endif
