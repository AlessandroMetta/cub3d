/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:37:42 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:24:24 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../mlx/mlx.h"
# include "main.h"
# include <math.h>

typedef struct s_eng
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	rdx;
	double	rdy;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	int		side;
	double	pwd;
	double	w_x;
	int		map_x;
	int		map_y;
	int		x;
	double	*z_buff;
}	t_eng;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_tex
{
	t_img	*no;
	t_img	*we;
	t_img	*ea;
	t_img	*so;
	t_img	*sp;
}				t_tex;

typedef struct s_dda
{
	double	sdx;
	double	sdy;
	double	ddx;
	double	ddy;
	int		step_x;
	int		step_y;
}				t_dda;

typedef struct s_draw
{
	double	s_c[2];
	int		s_s[2];
	double	transf[2];
	int		d_s[2];
	int		d_e[2];
	int		tex_x;
	int		tex_y;
	int		d;
}				t_draw;

typedef struct s_sprite
{
	double	x;
	double	y;
}				t_sprite;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	double		bf;
	double		lr;
	double		rot;
	t_parse		parse;
	t_img		img;
	t_eng		eng;
	t_tex		tex;
	t_dda		dda;
	t_sprite	*spt;
	t_draw		drw;
}				t_vars;

void			window_main(t_parse *config);
void			put_pixel(t_img *data, int x, int y, int color);
void			engine_init(t_vars *vars);
void			raycaster(t_vars *vars);
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
int				win_close(t_vars *vars);
void			move(t_vars *vars);
void			save(t_vars *vars);
void			draw_line(t_vars *cub, int start, int end);
void			drawtex(t_vars *cub, int l_h, int d_s, int d_e);
void			spt_sort(t_vars *cub);
void			draw_sprites(t_vars *cub);
void			spt_init(t_vars *cub);

#endif
