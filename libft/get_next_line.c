/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:19:39 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/23 01:57:07 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*join_buff(char *buffer, char *tmp)
{
	char		*tmpjoined;

	if (tmp == NULL)
		return (ft_strdup(buffer));
	else
	{
		tmpjoined = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
		return (tmpjoined);
	}
}

char			*check_rest(char **rest)
{
	char		*ret;

	if (*rest == NULL)
		return (NULL);
	else
	{
		ret = ft_strdup(*rest);
		ft_strdel(&*rest);
	}
	return (ret);
}

int				n_position(char *tmp)
{
	int			i;

	i = 0;
	while (tmp[i] != '\n')
		i++;
	return (i);
}

char			*cut_buffer(char *tmp, char **rest)
{
	char		*tmpjoin;
	char		*tmp2;

	if ((tmp2 = ft_strchr(tmp, '\n')) != NULL)
	{
		tmpjoin = ft_strsub(tmp, 0, tmp2 - tmp);
		*rest = ft_strdup(tmp2 + 1);
		if (ft_strcmp(*rest, "\0") == 0)
			ft_strdel(&*rest);
		ft_strdel(&tmp);
		return (tmpjoin);
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rest = NULL;
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	tmp = check_rest(&rest);
	while (!ft_strchr(tmp, '\n') && ((ret = read(fd, buffer, BUFF_SIZE)) > 0))
	{
		buffer[ret] = '\0';
		tmp = join_buff(buffer, tmp);
	}
	if (ret == 0 && tmp == NULL)
		return (0);
	if (ret == -1)
	{
		ft_strdel(&tmp);
		return (-1);
	}
	*line = cut_buffer(tmp, &rest);
	return (1);
}
