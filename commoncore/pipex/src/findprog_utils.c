/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findprog_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:25:53 by titan             #+#    #+#             */
/*   Updated: 2023/10/31 09:22:43 by titan            ###   ########.fr       */
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
//Returns file path , a char ptr on the heap
//Note that access returns zero on success
char *find_exec(char *prog_name, char *path_var)
{
	char	**path_prefix;
	char	**path_prefix_ptr;
	char	*file_path;
	int		res;

	path_prefix = ft_split(path_var, ':');
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
	free(file_path);
	return (free_arr(NULL,path_prefix));
}
