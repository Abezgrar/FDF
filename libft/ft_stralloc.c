/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:54:29 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:05:26 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stralloc(char *s)
{
	char	*dest;
	int		i;

	i = ft_strlen(s);
	if ((dest = malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	return (dest);
}
