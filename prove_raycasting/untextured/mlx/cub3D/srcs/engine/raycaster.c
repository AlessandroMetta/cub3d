/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:24:34 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:50:47 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

void	ray_init(t_vars *cub)
{
	cub->eng.cam_x = 2 * cub->eng.x / (double)cub->parse.x_res - 1;
	cub->eng.rdx = -cub->eng.dir_x + cub->eng.plane_x * cub->eng.cam_x;
	cub->eng.rdy = -cub->eng.dir_y + cub->eng.plane_y * cub->eng.cam_x;
	cub->eng.map_x = (int)cub->eng.pos_x;
	cub->eng.map_y = (int)cub->eng.pos_y;
}

void	direction(t_vars *cub)
{
	cub->dda.ddx = fabs(1 / cub->eng.rdx);
	cub->dda.ddy = fabs(1 / cub->eng.rdy);
	if (cub->eng.rdx < 0)
	{
		cub->dda.step_x = -1;
		cub->dda.sdx = (cub->eng.pos_x - cub->eng.map_x) * cub->dda.ddx;
	}
	else
	{
		cub->dda.step_x = 1;
		cub->dda.sdx = (cub->eng.map_x + 1.0 - cub->eng.pos_x)
			* cub->dda.ddx;
	}
	if (cub->eng.rdy < 0)
	{
		cub->dda.step_y = -1;
		cub->dda.sdy = (cub->eng.pos_y - cub->eng.map_y)
			* cub->dda.ddy;
	}
	else
	{
		cub->dda.step_y = 1;
		cub->dda.sdy = (cub->eng.map_y + 1.0 - cub->eng.pos_y)
			* cub->dda.ddy;
	}
}

void	dda(t_vars *cub)
{
	int		wa_hit;

	wa_hit = 0;
	while (!wa_hit)
	{
		if (cub->dda.sdx < cub->dda.sdy)
		{
			cub->dda.sdx += cub->dda.ddx;
			cub->eng.map_x += cub->dda.step_x;
			cub->eng.side = 0;
		}
		else
		{
			cub->dda.sdy += cub->dda.ddy;
			cub->eng.map_y += cub->dda.step_y;
			cub->eng.side = 1;
		}
		if (cub->parse.map[cub->eng.map_x][cub->eng.map_y] == '1')
			wa_hit = 1;
	}
}

void	side(t_vars *cub)
{
	if (cub->eng.side == 0)
		cub->eng.pwd = (cub->eng.map_x - cub->eng.pos_x + \
			(1 - cub->dda.step_x) / 2) / cub->eng.rdx;
	else
		cub->eng.pwd = (cub->eng.map_y - cub->eng.pos_y + \
			(1 - cub->dda.step_y) / 2) / cub->eng.rdy;
}

void	raycaster(t_vars *cub)
{
	int		draw_start;
	int		draw_end;
	int		line_height;

	cub->eng.x = 0;
	while (cub->eng.x < cub->parse.x_res)
	{
		ray_init(cub);
		direction(cub);
		dda(cub);
		side(cub);
		line_height = (int)(cub->parse.y_res / cub->eng.pwd);
		draw_start = -line_height / 2 + cub->parse.y_res / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + cub->parse.y_res / 2;
		if (draw_end > cub->parse.y_res)
			draw_end = cub->parse.y_res - 1;
		drawtex(cub, line_height, draw_start, draw_end);
		draw_line(cub, draw_start, draw_end);
		cub->eng.z_buff[cub->eng.x] = cub->eng.pwd;
		cub->eng.x++;
	}
	draw_sprites(cub);
	save(cub);
}
