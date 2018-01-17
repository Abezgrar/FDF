/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fornorme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:43:31 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/24 00:16:18 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			ouloulou(char *str, int i)
{
	if (str[i] && ((str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57)) ||
				(str[i] >= 48 && str[i] <= 57)))
		return (1);
	return (0);
}

int			ft_count_point(char *str)
{
	int		i;
	int		pts;

	i = 0;
	pts = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (ouloulou(str, i) == 1)
			pts++;
		else
			return (-1);
		while (str[i] && (str[i] == '-' || (str[i] >= 48 && str[i] <= 57)))
			i++;
		if (str[i] == ',')
			while (str[i] != ' ')
				i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != '-' && str[i] < 48 && str[i] > 57)
			return (-1);
	}
	return (pts == 0) ? -1 : pts;
}

void		refresh(t_window *w)
{
	mlx_clear_window(w->mlx, w->win_ptr);
	affich(w);
	print_map(w);
}

int			key(int keycode, t_window *param)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == 24 && (param)->zoom < 20)
		param->zoom++;
	if (keycode == 27 && (param)->zoom > 1)
		param->zoom--;
	if (keycode == 126 && (param)->y_start > 0)
		param->y_start = param->y_start + 10;
	if (keycode == 125 && (param)->y_start < 2000)
		param->y_start = param->y_start - 10;
	if (keycode == 124 && (param)->x_start < 2000)
		param->x_start = param->x_start + 10;
	if (keycode == 123 && (param)->x_start > 10)
		param->x_start = param->x_start - 10;
	if (keycode == 69 && (param)->z_start < 600)
		param->z_start = param->z_start + 0.10;
	if (keycode == 78 && (param)->z_start > -600)
		param->z_start = param->z_start - 0.10;
	if (keycode == RESET)
	{
		param->x_start = 750;
		param->y_start = 750;
	}
	refresh((param));
	return (0);
}

void		print_pixel(t_window *w, int x, int y, int z)
{
	if (x > HGT || y < 0 || y > WTH || x < 0)
		return ;
	if (z == 0)
		mlx_pixel_put(w->mlx, w->win_ptr, x, y, 0x00FFFFFF);
	else if (z > 0)
		mlx_pixel_put(w->mlx, w->win_ptr, x, y, 0x00FF0000);
	else if (z < 0)
		mlx_pixel_put(w->mlx, w->win_ptr, x, y, 0x00000CFF);
}
