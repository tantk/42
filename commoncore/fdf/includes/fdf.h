/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:18:48 by titan             #+#    #+#             */
/*   Updated: 2023/11/14 04:46:42 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/*
 * 4. Transformation Matrices:
 * 5. Rotation and Transformation Functions:
 * 6. Camera Perspective:
 * 7. User Interaction: rotate/zoom
 * 8. Rendering Loop:
 */
typedef struct s_3Dpoint{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_3Dpoint;

typedef struct s_matrix{
	unsigned int	mat_row;
	unsigned int	mat_col;
	t_3Dpoint		*content;
}	t_matrix;

typedef struct s_map
{
	t_matrix		*matrix;
	unsigned int	map_row;
	unsigned int	map_col;

}	t_map;

//lst for parsing file into *t_matrix
//used only during parsing,free lst and point tmatrix to content;
//motivation is to reduce operation during parsing by using linklst
//linklst doesnt need to find out all memory needed for the entire map first
//lst uses more memory,need 8 byte for 1 point on the map.
//reduce memory usage by changing to just *content after parsing, and free lst
//optimization done here are probably insignficant to modern computer
// All these are for learning purpose
typedef struct s_mlst{
	t_3Dpoint		*content;
	struct s_mlst	*next;
}	t_mlst;

typedef struct s_mlst_holder{
	t_mlst			*head;
	t_mlst			*last;
	unsigned int	size;
	unsigned int	col;
	unsigned int	cur_col;
	unsigned int	cur_row;
}	t_mlst_hld;

void		fdf_lstadd(t_mlst_hld *hld);
t_3Dpoint	*lst_to_pts(t_mlst_hld hld);
void		fdf_parse_line(t_mlst_hld *hld, char *line);

t_map	*create_map(char *file_path);


int			ret_errmsg(const char *msg);
char		*ret_errmsg_char(const char *msg);
int			ret_errmsg_cust_msg(const char *msg, int errorcode);
void		exit_error(const char *msg);
void		error_unknown_char(char c, char*line);
#endif
