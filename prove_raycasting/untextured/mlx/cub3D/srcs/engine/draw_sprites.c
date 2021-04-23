/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:23:36 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:43:27 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

void	put_spt(t_vars *cub, int y)
{
	while (y < cub->drw.d_e[1])
	{
		cub->drw.tex_y = (int)(((((int)((y) * 256 - cub->parse.y_res * 128 + \
			cub->drw.s_s[0] * 128)) * cub->tex.sp->h) / cub->drw.s_s[0]) / 256);
		if (((int *)cub->tex.sp->addr)[(cub->tex.sp->w * cub->drw.tex_y + \
			cub->drw.tex_x)] != 0)
			put_pixel(&cub->img, cub->drw.d_s[0], y, ((int *)cub->tex.sp->addr) \
				[(cub->tex.sp->w * cub->drw.tex_y + cub->drw.tex_x)]);
		y++;
	}
}

void	s_e_init(t_vars *cub)
{
	cub->drw.d_s[0] = (int)(-cub->drw.s_s[0] / 2 + cub->drw.s_s[1]);
	if ((int)cub->drw.d_s[0] < 0)
		cub->drw.d_s[0] = 0;
	cub->drw.d_s[1] = (int)(-cub->drw.s_s[0] / 2 + cub->parse.y_res / 2);
	if ((int)cub->drw.d_s[1] < 0)
		cub->drw.d_s[1] = 0;
	cub->drw.d_e[0] = (int)(cub->drw.s_s[0] / 2 + cub->drw.s_s[1]);
	if ((int) cub->drw.d_e[0] >= cub->parse.x_res)
		cub->drw.d_e[0] = cub->parse.x_res - 1;
	cub->drw.d_e[1] = (int)(cub->drw.s_s[0] / 2 + cub->parse.y_res / 2);
	if ((int) cub->drw.d_e[1] >= cub->parse.y_res)
		cub->drw.d_e[1] = cub->parse.y_res - 1;
}

void	drw_init(t_vars *cub, double *i_d, int i)
{
	cub->drw.s_c[0] = (double)(cub->spt[i].x - cub->eng.pos_x);
	cub->drw.s_c[1] = (double)(cub->spt[i].y - cub->eng.pos_y);
	*i_d = (double)(1.0 / (cub->eng.plane_x * cub->eng.dir_y - \
		cub->eng.dir_x * cub->eng.plane_y));
	cub->drw.transf[0] = (double)(*i_d * (cub->eng.dir_y * cub->drw.s_c[0] - \
		cub->eng.dir_x * cub->drw.s_c[1]));
	cub->drw.transf[1] = (double)((- *i_d * (-cub->eng.plane_y * cub->drw.s_c[0] \
	 + cub->eng.plane_x * cub->drw.s_c[1])));
	cub->drw.s_s[1] = (int)((cub->parse.x_res / 2) * \
		(1 + cub->drw.transf[0] / cub->drw.transf[1]));
	cub->drw.s_s[0] = abs((int)(cub->parse.y_res / cub->drw.transf[1]));
}

int	is_in_range(t_vars *cub)
{
	return (cub->drw.transf[1] > 0 && \
			cub->drw.d_s[0] > 0 && \
			cub->drw.d_s[0] < cub->parse.x_res && \
			cub->drw.transf[1] <= cub->eng.z_buff[cub->drw.d_s[0]]);
}

void	draw_sprites(t_vars *cub)
{
	int		i;
	double	i_d;
	int		y;

	i = 0;
	while (i < cub->parse.sp_num)
	{
		drw_init(cub, &i_d, i);
		s_e_init(cub);
		while (cub->drw.d_s[0] < cub->drw.d_e[0])
		{
			cub->drw.tex_x = (int)(256 * (cub->drw.d_s[0] - \
				(-cub->drw.s_s[0] / 2 + cub->drw.s_s[1])) * \
				cub->tex.sp->w / cub->drw.s_s[0]) / 256;
			y = cub->drw.d_s[1];
			if (is_in_range(cub))
				put_spt(cub, y);
			cub->drw.d_s[0]++;
		}
		i++;
	}
}
