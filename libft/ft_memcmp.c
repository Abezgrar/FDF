/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:42:03 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:14:03 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*d1;
	const char	*d2;
	int			i;
	int			j;

	j = (int)n;
	d1 = (const char *)s1;
	d2 = (const char *)s2;
	i = 0;
	while (i < j)
	{
		if (d1[i] == d2[i])
			i++;
		else
			return ((unsigned char)d1[i] - (unsigned char)d2[i]);
	}
	return (0);
}
