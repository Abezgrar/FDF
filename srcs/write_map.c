/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:29:07 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/22 22:29:09 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_negative(char *str)
{
	if (str && str[0] == '-')
		return (-1);
	return (1);
}

int			get_next_nbr(char *str)
{
	int		negat;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	negat = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if ((negat = is_negative(&str[i]) == -1))
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		if ((ret >= 0 && ret < 214748364))
			ret = (ret * 10) + str[i] - '0';
		i++;
	}
	if (negat)
		ret = -ret;
	return (ret);
}

void		full_line(int *map, char *str, int size)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < size)
	{
		map[i] = get_next_nbr(&str[j]);
		i++;
		if (str[j] == ',' || str[j + 1] == ',')
			while (str[j] != ' ')
				j++;
		while (str[j] && ((str[j] >= 48 && str[j] <= 57) || str[j] == '-'))
			j++;
		while (str[j] && str[j] == ' ')
			j++;
	}
}

void		full_map(int **map, char *name, int size)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		full_line(map[i], line, size);
		free(line);
		i++;
	}
}

void		write_map(t_window *w)
{
	int		i;

	i = 0;
	w->map = (int**)malloc(sizeof(int*) * w->size_vertic);
	while (i < w->size_vertic)
	{
		w->map[i] = (int*)malloc(sizeof(int) * w->size_hori);
		i++;
	}
	full_map(w->map, w->name_file, w->size_hori);
}
