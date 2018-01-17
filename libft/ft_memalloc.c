/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:11:01 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:13:09 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*dest;

	dest = malloc(sizeof(void) * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}
