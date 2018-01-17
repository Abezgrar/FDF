/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:14:32 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 08:46:32 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		tab[4];
	char	*dest;

	if (!(s1 && s2))
		return (NULL);
	tab[0] = ft_strlen(s1) + 1;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = ft_strlen(s1) + ft_strlen(s2);
	if ((dest = (char *)malloc(sizeof(char) * tab[3] + 1)) == NULL)
		return (NULL);
	while (tab[1] < tab[3])
	{
		while (tab[1] < (tab[0] - 1))
		{
			dest[tab[1]] = s1[tab[1]];
			tab[1]++;
		}
		dest[tab[1]] = s2[tab[2]];
		tab[1]++;
		tab[2]++;
	}
	dest[tab[1]] = '\0';
	return (dest);
}
