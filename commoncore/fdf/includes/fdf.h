/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:18:48 by titan             #+#    #+#             */
/*   Updated: 2023/11/11 20:50:28 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../mlx_linux/mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

/*
 * 4. Transformation Matrices:
 * 5. Rotation and Transformation Functions:
 * 6. Camera Perspective:
 * 7. User Interaction: rotate/zoom
 * 8. Rendering Loop:
 */
typedef struct s_3Dpoint{
	int	x;
	int	y;
	int	z;
	int color;
} t_3Dpoint;

typedef struct s_matrix{
	unsigned int	row;
	unsigned int	col;
	t_3Dpoint		*content;
} t_matrix;

typedef struct s_map
{
	t_matrix	matrix;

} t_map;

//lst for parsing file into *t_matrix
//used only during parsing,free afterwards
typedef struct s_mlst{
	t_3Dpoint		*content;
	struct s_mlst	*next;
} t_mlst;

typedef struct s_mlst_holder{
	t_mlst			*head;
	t_mlst			*last;
	unsigned int	size;
	unsigned int	row;
	unsigned int	col;
	unsigned int	cur_x;
	unsigned int	cur_y;
} t_mlst_hld;

int	ret_errmsg(const char *msg);
char	*ret_errmsg_char(const char *msg);
int		ret_errmsg_cust_msg(const char *msg, int errorcode);
void	exit_error(const char *msg);

#endif
