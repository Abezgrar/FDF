/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:52:47 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:12:33 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret2;
	t_list	*prev;

	ret = NULL;
	if (lst && f)
	{
		ret = (*f)(lst);
		prev = ret;
		lst = lst->next;
		while (lst)
		{
			ret2 = (*f)(lst);
			prev->next = ret2;
			prev = ret2;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (ret);
}
