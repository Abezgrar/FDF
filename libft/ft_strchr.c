/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 04:06:02 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/17 07:35:22 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	occ;

	i = 0;
	occ = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == occ)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && occ == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
