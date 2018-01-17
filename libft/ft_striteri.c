/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 05:52:00 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 08:14:48 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	index;

	if (s && f)
	{
		index = ft_strlen(s);
		i = 0;
		while (i < index)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
