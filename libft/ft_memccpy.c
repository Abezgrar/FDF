/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:15:41 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:13:25 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	char			*dest;
	const char		*srcs;

	dest = (char *)dst;
	srcs = (char *)src;
	index = 0;
	while (index < n)
	{
		dest[index] = srcs[index];
		if (srcs[index] == c)
			return (dest + index + 1);
		index++;
	}
	return (NULL);
}
