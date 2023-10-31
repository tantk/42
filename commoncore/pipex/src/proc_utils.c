/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:48:06 by titan             #+#    #+#             */
/*   Updated: 2023/10/31 13:08:09 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	redir_fd(int fd1, int fd2)
{
	int res;

	if (fd1 == fd2)
		return (ret_errmsg("function redir_fd dup2 same fd"));
	res = dup2(fd1, fd2);
	if (res == -1)
		return (ret_errmsg("function redir_fd dup2:"));
	res = close(fd1);
	if (res == -1)
		return (ret_errmsg("function redir_fd close:"));
	return (1);
}

// setup fd
int	pop_filefd(t_proc *proc, char *infile, char *outfile)
{
	if (infile)
		proc -> iofile_fd[0] = open(infile,O_RDONLY);
	if (proc -> iofile_fd[0] == -1)
		return(ret_errmsg("error with infile"));
	if (outfile)
		proc -> iofile_fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (proc -> iofile_fd[1] == -1)
		return(ret_errmsg("error with outfile"));
	return (1);
}

char	*get_envpath(char *envp[])
{
	int	i;
	int	cmp;
	char *env_var;

	i = 0;
	env_var = envp[i];
	cmp =  ft_strncmp(env_var, "PATH", 4);
	while (env_var && cmp)
	{
		i++;
		env_var = envp[i];
		if (env_var)
			cmp =  ft_strncmp(env_var, "PATH", 4);
	}
	if (!env_var)
		return (ret_errmsg_char("Env path not found"));
	return (env_var);
}

int	prep_proc(t_proc *proc, char *cmd_str, char *env_path)
{
	int	err;

	proc -> cmd_arr = pp_parse_cmd(cmd_str);
	if (!proc -> cmd_arr)
		return(ret_errmsg("prep_proc_cmd_str"));
	proc -> prog_path = find_exec(*(proc -> cmd_arr), env_path);
	if (!proc -> prog_path)
		return (nil_prog_err(*proc -> cmd_arr));
	err = pipe(proc -> pipe_fd);
	if (err == -1)
		return (ret_errmsg("pipe err"));
	return (1);
}

int	init_proc(t_proc *proc, int argc, char** argv, char **envp)
{
	int err;

	err = 0;
	proc -> pipe_fd[0] = 0;
	proc -> pipe_fd[1] = 0;
	proc -> prev_read_fd = 0;
	err = pop_filefd(proc, argv[1], argv[argc - 1]);
	if (err == -1)
		return ret_errmsg("init_proc, filefd");
	proc -> pid = 0;
	proc -> cmd_arr = NULL;
	proc -> exec_env = envp;
	if (!proc ->exec_env)
		return ret_errmsg("init_proc, null env path");
	proc -> prog_path = NULL;
	return (1);
}
