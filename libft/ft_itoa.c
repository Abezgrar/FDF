/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:41:37 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:10:43 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_zero(int n)
{
	char		*zero;

	n = 0;
	if ((zero = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

static int		ft_sizer(int n)
{
	int			size;

	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*ret;
	int			size;

	i = 0;
	if (n == 0)
		return (ft_zero(n));
	size = ft_sizer(n);
	if ((ret = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	ret[size] = '\0';
	size--;
	if (n < 0)
		ret[0] = '-';
	while (n != 0)
	{
		i = n % 10;
		if (n < 0)
			i = i * -1;
		ret[size] = (char)i + '0';
		size--;
		n = n / 10;
	}
	return (ret);
}
