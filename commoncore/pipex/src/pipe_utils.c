/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:25:53 by titan             #+#    #+#             */
/*   Updated: 2023/10/27 05:03:26 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "../includes/pipex.h"
static char	*pp_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc((s1_len + s2_len + 2) * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	result[s1_len] = '/';
	ft_memcpy(result + s1_len + 1, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}

// Replace std input fd by the fd parameter
int	redir_io(char *filepath, int fd1, int fd2,int rwx)
{
	int	res;

	res = access(filepath, rwx);
	if (res == -1)
		return (ret_errmsg("function redir_io:"));
	res = dup2(fd1, fd2);
	if (res == -1)
		return (ret_err());
	close(fd1);
	return (1);
}

int	redir_fd(int fd1, int fd2)
{
	int res;

	res = dup2(fd1, fd2);
	if (res == -1)
		return ((ret_errmsg("function redir_fd:")));
	return (1);

}

static char *free_arr(char *file_path, char** arr)
{
	while(*arr)
	{
		free(*arr);
		arr++;
	}
	return(file_path);
}

//home/titan/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
char *find_exec(char *prog_name, char *path_var)
{
	char	**path_prefix;
	char	**path_prefix_ptr;
	char	*file_path;
	int		res;

	path_prefix = ft_split(prog_name, ':');
	if (!path_prefix || !*path_prefix)
		return (ret_errmsg_char("Error at find_exec, ft_split"));
	path_prefix_ptr = path_prefix;
	file_path = pp_strjoin(*path_prefix_ptr,prog_name);
	while(*path_prefix_ptr)
	{
		res = access(file_path, X_OK);
		if (!res)
			return(free_arr(file_path,path_prefix));
		path_prefix_ptr++;
	}
	return (NULL);
}
