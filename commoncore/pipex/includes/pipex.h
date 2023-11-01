/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:52:48 by titan             #+#    #+#             */
/*   Updated: 2023/11/01 16:06:04 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//24 bytes
typedef struct s_lst_holder{
	t_lst			*head;
	t_lst			*last;
	unsigned int	size;
}	t_hld;

typedef struct s_proc{
	int		pipe_fd[2];
	int		iofile_fd[2];
	pid_t	pid;
	char	**cmd_arr;
	char	**exec_env;
	char	*prog_path;
	int		prev_read_fd;
}	t_proc;

int		fork_proc(t_proc *proc, int argc, int counter);
int		exec_pipes(t_proc *proc, int argc, char **argv);
int		pipex(int argc, char **argv, char **envp);

int		redir_fd(int fd1, int fd2);
int		pop_filefd(t_proc *proc, char *infile, char *outfile);
char	*get_envpath(char *envp[]);
int		prep_proc(t_proc *proc, char *cmd_str, char *env_path);
int		init_proc(t_proc *proc, int argc, char **argv, char **envp);

char	*find_exec(char *prog_name, char *path_var);

char	**pp_parse_cmd(const char *cmd);

void	pp_hdlclearstruct(t_hld *hld);
int		pp_lstadd(t_hld *hld, char const *str);
void	pp_init_hld(t_hld *hld);
char	**pp_get_content(t_hld *hld);

int		nil_prog_err(char *prog_name);
int		ret_errmsg(const char *msg);
char	*ret_errmsg_char(const char *msg);
int		ret_err_cust_msg(const char *msg, int errorcode);
int		exit_status(int status);
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
