/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:34:32 by titan             #+#    #+#             */
/*   Updated: 2023/10/31 09:31:09 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Fork and exec child process
// if counter == 2 means first process
// if counter == argc - 3 means last process
int fork_proc(t_proc *proc, int argc, int counter)
{
	int	err;

	err = 0;
	proc -> pid = fork();
	if (proc -> pid == -1)
		return(ret_errmsg("Fork:"));
	if (proc -> pid != 0)
		return (proc -> pid);
	if (counter == 2)
		err = redir_fd(proc -> iofile_fd[0], STDIN_FILENO);
	else
		err = redir_fd(proc -> pipe_fd[0], STDIN_FILENO);
	if (err == -1)
		return(ret_errmsg("redir_fd stdin err"));
	if (counter == argc - 3)
		err = redir_fd(proc -> iofile_fd[1], STDOUT_FILENO);
	else
		err = redir_fd(proc -> pipe_fd[1], STDOUT_FILENO);
	if (err == -1)
		return(ret_errmsg("redir_fd stdout err"));
	err = execve(proc -> prog_path, proc -> cmd_arr,proc -> exec_env);
	return (-1);
}

int	exec_pipes(t_proc *proc, int argc, char **argv)
{
	int	counter;
	int	end_counter;
	int	err;
	int	wstatus;
	char	*env_path;

	err = 0;
	counter = 2;
	end_counter = argc - 3;
	env_path = get_envpath(proc-> exec_env);
	while(counter <= end_counter)
	{
		err = prep_proc(proc, argv[counter], env_path);
		if (err == -1)
			return (ret_errmsg("exec_pipes prep_proc"));
		proc -> pid = fork_proc(proc, argc, counter);
		err = wait(&wstatus);
		if (exit_status(wstatus) == -1 || err == -1)
			return (ret_errmsg("fork_proc "));
		err = close(proc -> pipe_fd[1]);
		if (err == -1)
			return (ret_errmsg("close pipefd 1"));
		counter++;
	}
	return (1);
}

//manager
int	pipex(int argc, char **argv, char **envp)
{
	t_proc	proc;
	int		err;

	err = init_proc(&proc, argc, argv, envp);
	if (err == -1)
		return (ret_errmsg("pipex init_proc"));
	err = exec_pipes(&proc, argc, argv);
	if (err == -1)
		return (ret_errmsg("pipex exec_pipes"));
	err = close(proc.iofile_fd[0]);
	if (err == -1)
		return (ret_errmsg("pipex close fd in"));
	err = close(proc.iofile_fd[1]);
	if (err == -1)
		return (ret_errmsg("pipex close fd out"));
	return (1);
}
