/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:26:23 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/23 23:34:25 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_pas(t_pts p1, t_pts p2, t_calc *c)
{
	c->z = (double)p1.z;
	c->pas_z = (double)(p2.z - p1.z) / sqrt(((p2.x - p1.x) *
				(p2.x - p1.x))
			+ ((p2.y - p1.y) * (p2.y - p1.y)));
}

void		bresen(t_window *w, t_pts p1, t_pts p2)
{
	t_calc		calc;

	calc.dx = abs((p2.x - p1.x));
	calc.sx = p1.x < p2.x ? 1 : -1;
	calc.dy = abs((p2.y - p1.y));
	calc.sy = p1.y < p2.y ? 1 : -1;
	calc.err = (calc.dx > calc.dy ? calc.dx : -calc.dy) / 2;
	get_pas(p1, p2, &calc);
	while (!(p1.x == p2.x || p1.y == p2.y))
	{
		print_pixel(w, p1.x + w->x_start, p1.y + w->y_start, p1.z);
		calc.z += calc.pas_z;
		calc.e2 = calc.err;
		if (calc.e2 > -calc.dx)
		{
			calc.err -= calc.dy;
			p1.x += calc.sx;
		}
		if (calc.e2 < calc.dy)
		{
			calc.err += calc.dx;
			p1.y += calc.sy;
		}
	}
}

void		fill_pts_stru(int i, int j, int **map, t_window *w)
{
	t_pts	p1;
	t_pts	p2;

	if (i < w->size_vertic - 1)
	{
		p1.x = -5 * w->zoom * ((sqrt(2) / 2)) * (i - j);
		p1.y = -5 * w->zoom * MAUR;
		p1.z = map[i][j] * w->z_start;
		p2.x = -5 * w->zoom * ((sqrt(2) / 2)) * ((i + 1) - j);
		p2.y = -5 * w->zoom * LOL;
		p2.z = map[i + 1][j] * w->z_start;
		bresen(w, p1, p2);
	}
	if (j < w->size_hori - 1)
	{
		p1.x = -5 * w->zoom * ((sqrt(2) / 2)) * (i - j);
		p1.y = -5 * w->zoom * MAUR;
		p1.z = map[i][j] * w->z_start;
		p2.x = -5 * w->zoom * ((sqrt(2) / 2)) * (i - (j + 1));
		p2.y = -5 * w->zoom * LUL;
		p2.z = map[i][j + 1] * w->z_start;
		bresen(w, p1, p2);
	}
}

void		print_map(t_window *w)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < w->size_vertic)
	{
		while (j < w->size_hori)
		{
			fill_pts_stru(i, j, w->map, w);
			j++;
		}
		i++;
		j = 0;
	}
}

void		trace_map(t_window *w)
{
	mlx_hook(w->win_ptr, 2, (1L << 0), key, (void*)w);
	refresh(w);
	mlx_loop(w->mlx);
}
