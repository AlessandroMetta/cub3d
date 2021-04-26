/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:36:50 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/26 14:41:27 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	render_frame(t_vars *cub)
{
	cub->img.img = mlx_new_image(cub->mlx, cub->parse.x_res, \
		cub->parse.y_res);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp, \
		&cub->img.line_length, &cub->img.endian);
	move(cub);
	spt_sort(cub);
	raycaster(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img.img);
	return (0);
}

void	tex_init(t_vars *cub)
{
	cub->tex.no->img = mlx_xpm_file_to_image(cub->mlx, cub->parse.no_path, \
		&cub->tex.no->w, &cub->tex.no->h);
	cub->tex.no->addr = mlx_get_data_addr(cub->tex.no->img, &cub->tex.no->bpp, \
		&cub->tex.no->line_length, &cub->tex.no->endian);

	cub->tex.so->img = mlx_xpm_file_to_image(cub->mlx, cub->parse.so_path, \
		&cub->tex.so->w, &cub->tex.so->h);
	cub->tex.so->addr = mlx_get_data_addr(cub->tex.so->img, &cub->tex.so->bpp, \
		&cub->tex.so->line_length, &cub->tex.so->endian);

	cub->tex.we->img = mlx_xpm_file_to_image(cub->mlx, cub->parse.we_path, \
		&cub->tex.we->w, &cub->tex.we->h);
	cub->tex.we->addr = mlx_get_data_addr(cub->tex.we->img, &cub->tex.we->bpp, \
		&cub->tex.we->line_length, &cub->tex.we->endian);

	cub->tex.ea->img = mlx_xpm_file_to_image(cub->mlx, cub->parse.ea_path, \
		&cub->tex.ea->w, &cub->tex.ea->h);
	cub->tex.ea->addr = mlx_get_data_addr(cub->tex.ea->img, &cub->tex.ea->bpp, \
		&cub->tex.ea->line_length, &cub->tex.ea->endian);

	cub->tex.sp->img = mlx_xpm_file_to_image(cub->mlx, cub->parse.sp_path, \
		&cub->tex.sp->w, &cub->tex.sp->h);
	cub->tex.sp->addr = mlx_get_data_addr(cub->tex.sp->img, &cub->tex.sp->bpp, \
		&cub->tex.sp->line_length, &cub->tex.sp->endian);
}

void	window_main(t_parse *config)
{
	t_vars	cub;
	int		yres;

	cub.mlx = mlx_init();
	cub.tex.no = (t_img *)malloc(sizeof(t_img));
	cub.tex.so = (t_img *)malloc(sizeof(t_img));
	cub.tex.we = (t_img *)malloc(sizeof(t_img));
	cub.tex.ea = (t_img *)malloc(sizeof(t_img));
	cub.tex.sp = (t_img *)malloc(sizeof(t_img));
	yres = 1440;
	if (config->x_res > 2560)
		config->x_res = 2560;
	if (config->y_res > 1440)
		config->y_res = 1440;
	cub.parse = *config;
	cub.win = mlx_new_window(cub.mlx, config->x_res, config->y_res, "Cub3D");
	engine_init(&cub);
	tex_init(&cub);
	spt_init(&cub);
	mlx_hook(cub.win, 02, 1L << 02, key_press, &cub);
	mlx_hook(cub.win, 03, 1L << 03, key_release, &cub);
	mlx_hook(cub.win, 17, 1L << 02, win_close, &cub);
	mlx_loop_hook(cub.mlx, render_frame, &cub);
	mlx_loop(cub.mlx);
}
