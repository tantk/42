/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:18:48 by titan             #+#    #+#             */
/*   Updated: 2024/02/07 18:29:18 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include "../mlx_linux/mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define RESO_X 1024
# define RESO_Y 1024
# define TARGET 0.9

typedef struct s_read{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}	t_read;

typedef struct s_3Dpoint{
	double			x;
	double			y;
	double			z;
}	t_3D;

typedef struct s_matrix{
	t_3D			*content;
	t_3D			*rndr;
	unsigned int	*color_arr;
	unsigned int	mat_row;
	unsigned int	mat_col;
}	t_matrix;

typedef struct s_int_pt{
	int				x;
	int				y;
	unsigned int	color;
}	t_int_pt;

typedef struct s_map
{
	t_matrix		*matrix;
	double			scale;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			shift;
	double			offset_x;
	double			offset_y;
	unsigned int	map_row;
	unsigned int	map_col;
	int				fd;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		b_in_pix;
	int		l_len;
	int		endian;
}	t_img;

typedef struct s_draw_map
{
	t_3D			*rndr;
	t_img			*img;
	unsigned int	i;
	unsigned int	j;
	unsigned int	idx;
	unsigned int	map_row;
	unsigned int	map_col;
}	t_draw_map;

typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
}	t_display;

typedef struct s_param
{
	t_display	*d;
	t_map		*m;
}	t_param;

typedef struct s_line
{
	int			dx;
	int			dy;
	int			yi;
	int			xi;
	t_int_pt	pt1;
	t_int_pt	pt2;
	int			s1;
	int			s2;
	int			x;
	int			y;
	int			d;
}	t_line;

typedef struct s_mlst{
	t_read			*content;
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
t_3D		*lst_to_pts(t_mlst_hld hld);
void		fdf_parse_line(t_mlst_hld *hld, char *line, t_map *map, char *line2);

t_map	*create_map(char *file_path);

void	fdf_matmul_rndr(t_map *map);

t_display	*create_display();
void fdf_put_pixel(t_img *img, int x, int y,int color);

void	hook_all(t_display *d, t_map *m);

void	general_line(t_img *img, t_int_pt pt1, t_int_pt pt2);

void	create_scale(t_map *map);
void	create_shift(t_map *map);
void	shift_scale(t_3D *mat, int i, double shift, double scale);
void	shift_scale2(double *i, double *j, double shift, double scale);
void	create_offset(t_map *map);

void	draw_map(t_map *map, t_display *disp);
int			ret_errmsg(const char *msg);
char		*ret_errmsg_char(const char *msg);
int			ret_errmsg_cust_msg(const char *msg, int errorcode);
void		exit_error(const char *msg);
void		error_unknown_char(char c, char*line);

void	map_error(t_mlst_hld *hld, char *line, t_map *map);
#endif
