/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:30:01 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 09:12:23 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char		**tmp;
	int			tab[5];

	if (!s)
		return (NULL);
	tab[4] = 0;
	tab[2] = ft_count(s, c);
	tab[3] = 0;
	if ((tmp = malloc(sizeof(char *) * (tab[2] + 1))) == NULL)
		return (NULL);
	while (tab[2] > 0 && s[tab[3]])
	{
		tab[0] = 0;
		while (s[tab[3]] == c)
			tab[3]++;
		tab[1] = tab[3];
		tab[3]--;
		while (s[++tab[3]] != c && s[tab[3]] != '\0')
			tab[0]++;
		tmp[tab[4]] = ft_strsub(s, tab[1], tab[0]);
		tab[4]++;
		tab[2]--;
	}
	tmp[tab[4]] = NULL;
	return (tmp);
}
