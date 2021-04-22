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
			vars->side = 1;
		}
		else
		{
			vars->sideDistY += vars->deltaDistY;
			vars->mapY += vars->stepY;
			vars->side = 0;
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

int	render_next_frame(t_vars *vars)
{
	t_data	game;
	int vsop = 0;

	game.img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
		&game.line_length, &game.endian);
	
	while(vsop < screenWidth)
	{
		ddaValuesCalculator(vars, vsop);
		sideDistCalculator(vars);
		dda(vars);
		if(vars->side == 1)
			vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;
		else
			vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;
		vars->lineHeight = (screenHeight / vars->perpWallDist);
		ft_drawline(game, vars, vsop);
		vsop++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, game.img, 0, 0);
	mlx_destroy_image(vars->mlx, game.img);
	ft_keys(vars);
	return (0);
}
