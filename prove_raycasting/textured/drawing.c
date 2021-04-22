#include "lib.h"

void textureSetting(t_vars *vars, char **addr, int *width, int *height)
{
	if (vars->side == 1 && vars->rayDirX < 0)
	{
		*addr = vars->tex.we->addr;
		*width = vars->tex.we->w;
		*height= vars->tex.we->h;
	}
	else if (vars->side == 1 && vars->rayDirX > 0)
	{
		*addr = vars->tex.we->addr;
		*width = vars->tex.we->w;
		*height= vars->tex.we->h;
	}
	else if (vars->side == 0 && vars->rayDirY < 0)
	{
		*addr = vars->tex.we->addr;
		*width = vars->tex.we->w;
		*height= vars->tex.we->h;
	}
	else if (vars->side == 0 && vars->rayDirY > 0)
	{
		*addr = vars->tex.we->addr;
		*width = vars->tex.we->w;
		*height= vars->tex.we->h;
	}
}

void ft_drawtex(t_data img, t_vars *vars, int vsop)
{	
	int drawStart = -vars->lineHeight / 2 + screenHeight / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = vars->lineHeight / 2 + screenHeight / 2;
	if(drawEnd >= screenHeight)
		drawEnd = screenHeight - 1;
	int osop = 0;
	char *addr;
	int width;
	int height;
	textureSetting(vars, &addr, &width, &height);
	if (vars->side == 0)
		vars->wallX = vars->posY + vars->perpWallDist * vars->rayDirY;
	else
		vars->wallX = vars->posX + vars->perpWallDist * vars->rayDirX;
	vars->wallX -= floor(vars->wallX);
	int texX = (int)(vars->wallX * (double)width);
	if (vars->side == 0 && vars->rayDirX > 0)
		texX = width - texX - 1;
	if (vars->side == 1 && vars->rayDirX < 0)
		texX = width - texX - 1;
	double step = (drawStart - screenHeight / 2 + vars->lineHeight / 2) * (1.0 * height / vars->lineHeight);
	
	while(osop <= screenHeight)
	{
		if (osop <= drawStart)
			my_mlx_pixel_put(&img, vsop, osop, create_trgb(0, 0, 200, 200));
		if (drawStart < drawEnd)
		{
			step += (1.0 * height / vars->lineHeight);
			my_mlx_pixel_put(img.img, vsop, drawStart, ((int *)addr)[height * ((int)step & (height - 1)) + texX]);
		}
		if (osop < screenHeight  && osop >= drawEnd)
			my_mlx_pixel_put(&img, vsop, osop, create_trgb(0, 10, 100, 0));
		osop++;
	}
}
