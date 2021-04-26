/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:50:15 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/26 14:41:13 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

void	spawn_dir(t_vars *cub)
{
	cub->eng.dir_x = 0;
	cub->eng.dir_y = 0;
	cub->eng.plane_x = 0;
	cub->eng.plane_y = 0;
	if (cub->parse.spawn[2] == 'N')
	{
		cub->eng.dir_x = 1;
		cub->eng.plane_y = 0.66;
	}
	else if (cub->parse.spawn[2] == 'S')
	{
		cub->eng.dir_x = -1;
		cub->eng.plane_y = -0.66;
	}
	else if (cub->parse.spawn[2] == 'W')
	{
		cub->eng.dir_y = 1;
		cub->eng.plane_x = -0.66;
	}
	else
	{
		cub->eng.dir_y = -1;
		cub->eng.plane_x = 0.66;
	}
}

void	draw_line(t_vars *cub, int start, int end)
{
	int	i;

	i = 0;
	while (i < start)
	{
		put_pixel(&cub->img, cub->eng.x, i, cub->parse.ceiling);
		i++;
	}
	while (i < end)
		i++;
	while (i < cub->parse.y_res)
	{
		put_pixel(&cub->img, cub->eng.x, i, cub->parse.floor);
		i++;
	}
}

void	dt_init(t_vars *cub, char **address, int *width, int *height)
{
	if (cub->eng.side == 1 && cub->eng.rdy < 0)
	{
		*address = cub->tex.we->addr;
		*width = cub->tex.we->w;
		*height = cub->tex.we->h;
	}
	if (cub->eng.side == 1 && cub->eng.rdy > 0)
	{
		*address = cub->tex.ea->addr;
		*width = cub->tex.ea->w;
		*height = cub->tex.ea->h;
	}
	if (cub->eng.side == 0 && cub->eng.rdx < 0)
	{
		*address = cub->tex.no->addr;
		*width = cub->tex.no->w;
		*height = cub->tex.no->h;
	}
	if (cub->eng.side == 0 && cub->eng.rdx > 0)
	{
		*address = cub->tex.so->addr;
		*width = cub->tex.so->w;
		*height = cub->tex.so->h;
	}
}

void	drawtex(t_vars *cub, int l_h, int d_s, int d_e)
{
	char		*addr;
	int			t_w;	// texture width
	int			t_h;	// texture height
	int			t_x;	// texture texX
	double		t_p;	// texture step

	dt_init(cub, &addr, &t_w, &t_h);

	if (cub->eng.side == 0)
		cub->eng.w_x = cub->eng.pos_y + cub->eng.pwd * cub->eng.rdy;
	else
		cub->eng.w_x = cub->eng.pos_x + cub->eng.pwd * cub->eng.rdx;
	cub->eng.w_x -= floor((cub->eng.w_x));
	
	t_x = (int)(cub->eng.w_x * ((double)t_w));
	if (cub->eng.side == 0 && cub->eng.rdx > 0)
		t_x = t_w - t_x - 1;
	if (cub->eng.side == 1 && cub->eng.rdy < 0)
		t_x = t_w - t_x - 1;

	t_p = (d_s - cub->parse.y_res / 2 + l_h / 2) * (1.0 * t_h / l_h);

	while (d_s < d_e)
	{
		t_p += (1.0 * t_h / l_h);
		put_pixel(&cub->img, cub->eng.x, d_s, ((int *)addr)[t_h * ((int)t_p & (t_h - 1)) + t_x]);
		d_s++;
	}
}

void	engine_init(t_vars *cub)
{
	cub->eng.pos_x = cub->parse.spawn[0] + 0.5;
	cub->eng.pos_y = cub->parse.spawn[1] + 0.5;
	spawn_dir(cub);
	cub->spt = (t_sprite *)malloc(cub->parse.sp_num * sizeof(t_sprite));
	if (!cub->spt)
		ft_perror("Error\nMemory Allocation Failed");
	cub->eng.z_buff = (double *)malloc(cub->parse.x_res * sizeof(double));
	if (!cub->eng.z_buff)
		ft_perror("Error\nMemory Allocation Failed");
}
