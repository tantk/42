/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:22:11 by titan             #+#    #+#             */
/*   Updated: 2023/11/27 16:34:45 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_prog(void *param)
{
	t_param *p;

	p = (t_param *)param;
	mlx_destroy_window(p -> d -> mlx, p -> d -> mlx_win);
	exit(0);
}

void	hook_all(t_display *d, t_map *m)
{
	t_param p;

	p.d = d;
	p.m = m;
	mlx_hook(d -> mlx_win, 17, 0L,close_prog, &p);
}
