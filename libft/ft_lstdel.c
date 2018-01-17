/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:01:20 by abezgrar          #+#    #+#             */
/*   Updated: 2017/01/31 10:11:29 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*copy;
	t_list		*next_lst;

	copy = *alst;
	while (copy)
	{
		next_lst = copy->next;
		del(copy->content, copy->content_size);
		free(copy);
		copy = next_lst;
	}
	*alst = NULL;
}
