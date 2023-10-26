/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:34:32 by titan             #+#    #+#             */
/*   Updated: 2023/10/27 05:29:14 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int fork_proc(t_proc *proc)
{
	proc -> pid = fork();
	if (proc -> pid == -1)
		return(ret_errmsg("Fork:"));
	return (1);
}

int	child_proc(t_proc *proc, char *prog_path, char **cmd_arr)
{
	proc -> prd_pipe
}

int	exec_proc(t_proc *proc)
{
	char	*prog_path;
	char	**cmd_arr;

	cmd_arr = pp_get_content(proc -> cmd_holder);
	if (!cmd_arr)
		return(ret_errmsg("exec_proc"));
	prog_path = find_exec(*cmd_arr, proc->path);
	if (!prog_path)
		return (nil_prog_err(*cmd_arr));
	if (proc -> pid == 0)
	{

		execve(prog_path,cmd_arr,NULL);

	}

}
