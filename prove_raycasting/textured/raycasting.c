#include "lib.h"

static void dda (t_vars *vars)
{
	int hit = 0;
	while (hit == 0)
	{
		if(vars->sideDistX < vars->sideDistY)
		{
			vars->sideDistX += vars->deltaDistX;
			vars->mapX += vars->stepX;
			vars->side = 0;
		}
		else
		{
			vars->sideDistY += vars->deltaDistY;
			vars->mapY += vars->stepY;
			vars->side = 1;
		}
		if(map[vars->mapX][vars->mapY] == '1')
			hit = 1;
	}
}

static double deltaDistCalculator(double fct, double check)
{
	if (check == 0)
		return (0);
	if (fct == 0)
		return (1);
	return (fabs(1 / fct));
}

static void sideDistCalculator(t_vars *vars)
{
	if(vars->rayDirX < 0)
	{
		vars->stepX = -1;
		vars->sideDistX = (vars->posX - vars->mapX) * vars->deltaDistX;
	}
	else
	{
		vars->stepX = 1;
		vars->sideDistX = (vars->mapX + 1.0 - vars->posX) * vars->deltaDistX;
	}
	if(vars->rayDirY < 0)
	{
		vars->stepY = -1;
		vars->sideDistY = (vars->posY - vars->mapY) * vars->deltaDistY;
	}
	else
	{
		vars->stepY = 1;
		vars->sideDistY = (vars->mapY + 1.0 - vars->posY) * vars->deltaDistY;
	}
}

static void ddaValuesCalculator(t_vars *vars, int vsop)
{
	vars->cameraX = 2 * vsop / (double)screenWidth - 1; //x-coordinate in camera space
	vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
	vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
	vars->mapX = vars->posX;
	vars->mapY = vars->posY;
	vars->deltaDistX = deltaDistCalculator(vars->rayDirX, vars->rayDirY);
	vars->deltaDistY = deltaDistCalculator(vars->rayDirY, vars->rayDirX);
}

void textureInit(t_vars *vars)
{
	vars->tex.no->img = mlx_xpm_file_to_image(vars->mlx, "texture/mossy.xpm",
		&vars->tex.no->h, &vars->tex.no->w);
	vars->tex.no->img = mlx_get_data_addr(vars->tex.no->img, 
		&vars->tex.no->bits_per_pixel, &vars->tex.no->line_length,
		&vars->tex.no->endian);
	
	vars->tex.so->img = mlx_xpm_file_to_image(vars->mlx, "texture/redbrick.xpm",
		&vars->tex.so->w, &vars->tex.so->w);
	vars->tex.so->img = mlx_get_data_addr(vars->tex.so->img,
		&vars->tex.so->bits_per_pixel, &vars->tex.so->line_length,
		&vars->tex.so->endian);

	vars->tex.ea->img = mlx_xpm_file_to_image(vars->mlx, "texture/stone.xpm",
		&vars->tex.ea->w, &vars->tex.ea->w);
	vars->tex.ea->img = mlx_get_data_addr(vars->tex.ea->img,
	&vars->tex.ea->bits_per_pixel, &vars->tex.ea->line_length,
			&vars->tex.ea->endian);

	vars->tex.we->img = mlx_xpm_file_to_image(vars->mlx, "texture/wood.xpm",
		&vars->tex.we->w, &vars->tex.we->w);
	vars->tex.we->img = mlx_get_data_addr(vars->tex.we->img,
		&vars->tex.we->bits_per_pixel, &vars->tex.we->line_length,
		&vars->tex.we->endian);
}

int	render_next_frame(t_vars *vars)
{
	t_data	game;

	int vsop = 0;
	textureInit(vars);

	game.img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
		&game.line_length, &game.endian);
	
	while(vsop < screenWidth)
	{
		ddaValuesCalculator(vars, vsop);
		sideDistCalculator(vars);
		dda(vars);
		if(vars->side < 1)
			vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;
		else
			vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;
		ft_drawtex(game, vars, vsop);
		vsop++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, game.img, 0, 0);
	mlx_destroy_image(vars->mlx, game.img);
	ft_keys(vars);
	return (0);
}
