/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:00:37 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 08:35:45 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	int		i;
	char	*dest;

	if (s && f)
	{
		index = ft_strlen(s);
		i = 0;
		if ((dest = malloc((sizeof(char) * index) + 1)) == NULL)
			return (NULL);
		while (i < index)
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
