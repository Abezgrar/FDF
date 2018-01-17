/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 00:32:17 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 09:06:51 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count(char const *s, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		if (j > 0)
			count++;
		j = 0;
		if (s[i] == c)
			i++;
	}
	return (count);
}
