/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findprog_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:25:53 by titan             #+#    #+#             */
/*   Updated: 2023/11/04 08:04:59 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
	result[s1_len + s2_len + 1] = '\0';
	return (result);
}

static char	*free_arr(char *file_path, char **arr)
{
	char	**arr_ptr;

	arr_ptr = arr;
	while (*arr_ptr)
	{
		free(*arr_ptr);
		arr_ptr++;
	}
	free(arr);
	return (file_path);
}

static char	*skip_path(char *file_path)
{
	int	result;

	result = ft_strncmp(file_path, "PATH=", 5);
	if (!result)
		return (file_path + 5);
	return (file_path);
}

//Returns file path , a char ptr on the heap
//Note that access returns zero on success
char	*find_exec(char *prog_name, char *path_var)
{
	char	**path_prefix;
	char	**path_prefix_ptr;
	char	*file_path;
	int		res;

	path_prefix = ft_split(path_var, ':');
	if (!path_prefix || !*path_prefix)
		return (ret_errmsg_char("Error at find_exec, ft_split"));
	path_prefix_ptr = path_prefix;
	while (*path_prefix_ptr)
	{
		file_path = pp_strjoin(skip_path(*path_prefix_ptr), prog_name);
		res = access(file_path, X_OK);
		if (!res)
			return (free_arr(file_path, path_prefix));
		path_prefix_ptr++;
		free(file_path);
	}
	return (free_arr(NULL, path_prefix));
}
