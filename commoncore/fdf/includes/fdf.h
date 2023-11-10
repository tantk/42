/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:18:48 by titan             #+#    #+#             */
/*   Updated: 2023/11/10 22:40:05 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <errno.h>
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


#endif
