/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:50:16 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:15:13 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	i = 0;
	dst2 = (char *)dst;
	src2 = (const char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
	}
	return (dst);
}
