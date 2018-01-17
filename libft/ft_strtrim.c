/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 06:33:22 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:23:35 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_boul(char c)
{
	if (c != ' ' && c != '\n' && c != '\t' && c != ' ' && \
			c != '\n' && c != '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*dest;
	int		tab[3];

	if (!s)
		return (NULL);
	dest = NULL;
	tab[1] = ft_strlen(s) - 1;
	tab[2] = 0;
	if (ft_boul(s[tab[2]]) == 1 && ft_boul(s[tab[1]]) == 1)
	{
		dest = (char *)malloc(sizeof(char) * tab[1] + 1);
		return (dest ? ft_strcpy(dest, s) : NULL);
	}
	while (s[tab[2]] == ' ' || s[tab[2]] == '\n' || s[tab[2]] == '\t')
		tab[2]++;
	tab[0] = tab[2];
	while (s[tab[1]] == ' ' || s[tab[1]] == '\n' || s[tab[1]] == '\t')
		tab[1]--;
	if (tab[1] <= tab[0])
		return (ft_strdup(""));
	if ((dest = malloc((sizeof(char) * (tab[1] - tab[0])) + 2)) == NULL)
		return (NULL);
	dest = ft_strncpy(dest, &s[tab[0]], (tab[1] - tab[0] + 1));
	dest[tab[1] - tab[0] + 1] = '\0';
	return (dest);
}
