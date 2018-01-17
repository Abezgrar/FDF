/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:10:13 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:08:36 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == '\v') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	return (ret * sign);
}
