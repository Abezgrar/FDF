/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:25:18 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/24 03:40:59 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			check_lenght(int fd, int lenght, t_window *wind)
{
	if (lenght == 0)
	{
		close(fd);
		return (-1);
	}
	else
		wind->size_vertic = lenght;
	close(fd);
	return (lenght);
}

int			count_line(char *str, t_window *wind)
{
	int		size;
	char	*l;
	int		fd;
	int		lenght;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	l = NULL;
	size = 0;
	lenght = 0;
	while (get_next_line(fd, &l) > 0)
	{
		if (size == 0)
			size = ft_count_point(l);
		if (size != ft_count_point(l) || ft_count_point(l) == -1)
		{
			free(l);
			return (-1);
		}
		else
			wind->size_hori = size;
		free(l);
		++lenght;
	}
	return (check_lenght(fd, lenght, wind));
}

t_window	*struct_init(char **av)
{
	t_window *w;

	if (!(w = (t_window*)malloc(sizeof(t_window))))
	{
		ft_putstr("Malloc failed\n");
		return (0);
	}
	w->x_start = 600;
	w->y_start = 450;
	w->z_start = 0.1;
	w->zoom = 8;
	w->name_file = av[1];
	if (count_line(av[1], w) == -1)
	{
		free(w);
		return (0);
	}
	return (w);
}

int			main(int ac, char **av)
{
	t_window	*wind;

	wind = NULL;
	if (ac == 2)
	{
		if (!(wind = struct_init(av)))
		{
			ft_putstr("ERROR MAP NOT WELL SIZED\n");
			return (0);
		}
		write_map(wind);
		wind->mlx = mlx_init();
		wind->win_ptr = mlx_new_window(wind->mlx, HGT, WTH, "fdf");
		trace_map(wind);
	}
	else
		ft_putstr("1 seul fichier merci\n");
}
