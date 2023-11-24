/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:18:48 by titan             #+#    #+#             */
/*   Updated: 2023/11/24 08:15:54 by titan            ###   ########.fr       */
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

#define RESO_X 1024
#define RESO_Y 1024

typedef struct s_3Dpoint{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}	t_3Dpoint;

typedef struct s_matrix{
	unsigned int	mat_row;
	unsigned int	mat_col;
	t_3Dpoint		*content;
}	t_matrix;

typedef struct s_render_pt{
	double	x;
	double	y;
}	t_render_pt;

typedef struct s_map
{
	t_matrix		*matrix;
	t_render_pt		*ren_mat;
	unsigned int	map_row;
	unsigned int	map_col;
	unsigned int	reso_x;
	unsigned int	reso_y;
	double          scale;
	double	        min_x;
	double	        max_x;
	double	        min_y;
	double	        max_y;
	double			shift;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		b_in_pix;
	int		l_len;
	int		endian;
}	t_img;

typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
}	t_display;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_line;

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

void	fdf_matmul_rndr(t_map *map);

t_display	*create_display();
void fdf_put_pixel(t_img *img, int x, int y,int color);

void	draw_map(t_map *map, t_display *disp);
int			ret_errmsg(const char *msg);
char		*ret_errmsg_char(const char *msg);
int			ret_errmsg_cust_msg(const char *msg, int errorcode);
void		exit_error(const char *msg);
void		error_unknown_char(char c, char*line);
#endif
