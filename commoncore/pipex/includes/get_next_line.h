/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 08:15:52 by titan             #+#    #+#             */
/*   Updated: 2023/10/07 18:02:48 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_lst{
	char			*content;
	struct s_lst	*next;
}	t_lst;

typedef struct s_storage{
	int		err;
	int		content_len;
	int		last_len;
	int		last_read;
	t_lst	*head;
	t_lst	*last;
}	t_storage;

char	*get_next_line(int fd);
int		ft_lstadd(t_storage *storage, char *str, int len);
void	ft_lstclear(t_storage *storage);
char	*extract_line(t_storage *storage, int nl_idx);
void	store_leftover(t_storage *storage, int nl_idx);
#endif
