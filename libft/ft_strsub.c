/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:22:59 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/17 07:43:48 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*dest;

	if (s)
	{
		i = 0;
		if ((dest = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (i < len)
		{
			dest[i] = s[start];
			start++;
			i++;
		}
		dest[len] = '\0';
		return (dest);
	}
	return (NULL);
}
