/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:36:00 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/24 00:05:04 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			affich(t_window *w)
{
	mlx_string_put(w->mlx, w->win_ptr, 15, 20, 0xFFFFFF, "ZOOM +    =  +");
	mlx_string_put(w->mlx, w->win_ptr, 15, 40, 0xFFFFFF, "ZOOM -    =  -");
	mlx_string_put(w->mlx, w->win_ptr, 15, 60, 0xFFFFFF, "RESET MAP =  R");
	mlx_string_put(w->mlx, w->win_ptr, 15, 80, 0xFFFFFF, "MOVE MAP  =  ARROWS");
	mlx_string_put(w->mlx, w->win_ptr, 15, 100, 0xFFFFFF, "INCREASE Z=  num +");
	mlx_string_put(w->mlx, w->win_ptr, 15, 120, 0xFFFFFF, "DECREASE Z=  num -");
	mlx_string_put(w->mlx, w->win_ptr, 15, 140, 0xFFFFFF, "CLOSE FDF =  ESC");
}
