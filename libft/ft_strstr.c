/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 05:24:25 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:23:12 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;

	i = 0;
	if (ft_strcmp(little, "") == 0)
		return ((char *)big);
	while (big[i])
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
