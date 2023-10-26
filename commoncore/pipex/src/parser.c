/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:19:17 by titan             #+#    #+#             */
/*   Updated: 2023/10/26 07:33:52 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// ./pipex file ""
//./a.out "awk -F: " "{count++} END {printf \"count: %i\" , count}" "/etc/passwd"
//./a.out "sed" "s/And/But/" "etc/passwd"

//34 is double quote, 39 is single quote
static int is_special(char c)
{
	return (c == '{' || c == 34 || c == 39);
}

static int	find_counter(const char *str, char c)
{
	char	*counterpart;
	int		len;

	counterpart = ft_strrchr(str, c);
	len = (counterpart - str) + 1;
	if (len > 1)
		return (len);
	else
		return (-1);
}

//handle quotes and brackets
static char *handle_phrase(const char *str, char c, int *skip)
{
	int len;

	len = find_counter(str, c);
	if (c == 34 || c == 39)
	{
		str++;
		*skip += 1;
		len--;
	}
	if (len < 1)
		return (NULL);
	*skip += len;
	return (ft_substr(str, 0, len));
}

//dup till whitespace or null term
static char	*pp_strdup(const char *str, int *skip)
{
	int		len;
	char	*str_ptr

	len = 0;
	str_ptr = str;
	while (*str_ptr && *str_ptr != ' ')
	{
		len++;
		str_ptr++;
	}
	return (ft_substr(str, 0, len));
}

t_hld *parse(const char *cmd)
{
	t_hdl	*hld;
	int		err;
	int		skip;

	hld = (t_hld *)malloc(sizeof(t_hld));
	if (!hld)
		return (NULL);
	skip = 0;
	err = 0;
	while (*cmd)
	{
		if (is_special(*cmd))
			err = pp_lstadd(hld, handle_phrase(cmd, *cmd, &skip));
		else if (*cmd != ' ')
			err = pp_lstadd(hld, pp_strdup(cmd, &skip));
		else
			cmd++;
		if (err == -1)
			return (NULL);
		cmd += skip;
		skip = 0;
	}
	return (hld);
}
