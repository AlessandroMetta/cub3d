/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:33:54 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:52:24 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

void	spt_init(t_vars *cub)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (cub->parse.map[i])
	{
		j = 0;
		while (cub->parse.map[i][j])
		{
			if (cub->parse.map[i][j] == '2')
			{
				cub->spt[num].x = (double)i + 0.5;
				cub->spt[num].y = (double)j + 0.5;
				num++;
			}
			j++;
		}
		i++;
	}
}

double	spt_dist(t_sprite spt, double x, double y)
{
	return (((double)spt.x - x) * ((double)spt.x - x) + \
			((double)spt.y - y) * ((double)spt.y - y));
}

void	spt_sort(t_vars *cub)
{
	int		i;
	int		j;
	double	buff[2];

	i = 0;
	while (i < cub->parse.sp_num)
	{
		j = i + 1;
		while (j < cub->parse.sp_num)
		{
			if (spt_dist(cub->spt[j], cub->eng.pos_x, cub->eng.pos_y) > \
				spt_dist(cub->spt[i], cub->eng.pos_x, cub->eng.pos_y))
			{
				buff[0] = cub->spt[i].x;
				buff[1] = cub->spt[i].y;
				cub->spt[i].x = cub->spt[j].x;
				cub->spt[i].y = cub->spt[j].y;
				cub->spt[j].x = buff[0];
				cub->spt[j].y = buff[1];
			}
			j++;
		}
		i++;
	}
}
