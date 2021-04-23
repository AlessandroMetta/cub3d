/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:47:33 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:47:24 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

int	key_release(int keycode, t_vars *cub)
{
	if (keycode == 13 || keycode == 1)
		cub->bf = 0;
	if (keycode == 123 || keycode == 124)
		cub->rot = 0;
	if (keycode == 0 || keycode == 2)
		cub->lr = 0;
	return (0);
}

int	win_close(t_vars *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}

int	key_press(int keycode, t_vars *cub)
{
	if (keycode == 53)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		exit(0);
	}
	if (keycode == 13)
		cub->bf = -0.07;
	if (keycode == 1)
		cub->bf = 0.07;
	if (keycode == 0)
		cub->lr = -0.07;
	if (keycode == 2)
		cub->lr = 0.07;
	if (keycode == 123)
		cub->rot = -0.07;
	if (keycode == 124)
		cub->rot = 0.07;
	return (0);
}

void	walk(t_vars *cub)
{
	if (cub->bf)
	{
		if (cub->parse.map[(int)(cub->eng.pos_x + cub->eng.dir_x * cub->bf)] \
			[(int)(cub->eng.pos_y)] != '1')
			cub->eng.pos_x += cub->eng.dir_x * cub->bf;
		if (cub->parse.map[(int)(cub->eng.pos_x)] \
			[(int)(cub->eng.pos_y + cub->eng.dir_y * cub->bf)] != '1')
			cub->eng.pos_y += cub->eng.dir_y * cub->bf;
	}
	if (cub->lr)
	{
		if (cub->parse.map[(int)(cub->eng.pos_x - cub->eng.dir_y * cub->lr)] \
			[(int)(cub->eng.pos_y)] != '1')
			cub->eng.pos_x += -(cub->eng.dir_y * cub->lr);
		if (cub->parse.map[(int)(cub->eng.pos_x)] \
			[(int)(cub->eng.pos_y + cub->eng.dir_x * cub->lr)] != '1')
			cub->eng.pos_y += cub->eng.dir_x * cub->lr;
	}
}

void	move(t_vars *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	walk(cub);
	if (cub->rot)
	{
		old_dir_x = cub->eng.dir_x;
		old_plane_x = cub->eng.plane_x;
		cub->eng.dir_x = cub->eng.dir_x * cos(-cub->rot) - \
			cub->eng.dir_y * sin(-cub->rot);
		cub->eng.dir_y = old_dir_x * sin(-cub->rot) + \
			cub->eng.dir_y * cos(-cub->rot);
		cub->eng.plane_x = cub->eng.plane_x * cos(-cub->rot) - \
			cub->eng.plane_y * sin(-cub->rot);
		cub->eng.plane_y = old_plane_x * sin(-cub->rot) + \
			cub->eng.plane_y * cos(-cub->rot);
	}
}
