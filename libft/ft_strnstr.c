/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <abezgrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 05:39:20 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:22:25 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int		i;

	i = 0;
	if (ft_strcmp(lit, "") == 0)
		return ((char *)big);
	while (big[i] && (i + ft_strlen(lit)) <= len)
	{
		if (ft_strncmp(big + i, lit, ft_strlen(lit)) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
