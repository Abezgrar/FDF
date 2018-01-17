/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezgrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 01:29:31 by abezgrar          #+#    #+#             */
/*   Updated: 2017/11/23 23:55:33 by abezgrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# define HGT 1500
# define PLUS 24
# define MINUS 27
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define EIGHT 91
# define FIVE 87
# define TWO 84
# define FOUR 86
# define SIX 88
# define RESET 15
# define ESC 53
# define WTH 1500
# define MAUR ((0.7 *( map[i][j] * w->z_start)) - ((1 / sqrt(6)) * (i + j)))
# define LOL2 ((1 / sqrt(6)) * ((i + 1) + j))
# define LOL ((0.7 * (map[i + 1][j] * w->z_start)) - LOL2)
# define LUL2 ((1 / sqrt(6)) * (i + (j + 1)))
# define LUL ((0.7 *( map[i][j + 1] * w->z_start )) - LUL2)
# include <math.h>

typedef struct			s_window
{
	void				*win_ptr;
	void				*mlx;
	int					**map;
	char				*name_file;
	int					size_hori;
	int					size_vertic;
	int					x_start;
	int					y_start;
	int					zoom;
	float				z_start;
}						t_window;

typedef struct			s_pts
{
	int					x;
	int					y;
	int					z;
}						t_pts;

typedef struct			s_calc
{
	int					dx;
	int					sx;
	int					dy;
	int					sy;
	int					err;
	int					e2;
	double				pas_z;
	double				z;
}						t_calc;

void					write_map(t_window *w);
void					trace_map(t_window *w);
void					print_map(t_window *w);
void					bresen(t_window *w, t_pts p1, t_pts p2);
int						ft_count_point(char *str);
int						ouloulou(char *str, int i);
int						ft_count_point(char *str);
void					refresh(t_window *w);
int						key(int keycode, t_window *param);
void					affich(t_window *w);
void					print_pixel(t_window *w, int x, int y, int z);
#endif
