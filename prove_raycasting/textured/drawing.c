#include "lib.h"

static void textureSet(t_vars *vars, char **addr, int *width, int *height)
{
	if (vars->side == 0 && vars->rayDirX < 0)
	{
		*addr = vars->texN->addr;
		*width = vars->texN->wdh;
		*height = vars->texN->hgh;
	}
	else if (vars->side == 0 && vars->rayDirX > 0)
	{
		*addr = vars->texS->addr;
		*width = vars->texS->wdh;
		*height = vars->texS->hgh;
	}
	else if (vars->side == 1 && vars->rayDirY > 0)
	{
		*addr = vars->texE->addr;
		*width = vars->texE->wdh;
		*height = vars->texE->hgh;
	}
	else if (vars->side == 1 && vars->rayDirY < 0)
	{
		*addr = vars->texW->addr;
		*width = vars->texW->wdh;
		*height = vars->texW->hgh; 
	}
}

static void drawPixelsSet(t_vars *vars, double *wallX, int *texX, int wdh)
{
	if (vars->side == 0)
		*wallX = vars->posY + vars->perpWallDist * vars->rayDirY;
	else
		*wallX = vars->posX + vars->perpWallDist * vars->rayDirX;
	*wallX -= floor(*wallX);

	*texX = (int)(*wallX * ((double)wdh));
	if (vars->side == 0 && vars->rayDirX > 0)
		*texX = wdh - *texX - 1;
	if (vars->side == 1 && vars->rayDirY < 0)
		*texX = wdh - *texX - 1;
}

void drawTexture(t_data img, t_vars *vars, int vsop, int drawStart, int drawEnd)
{	
	int width, height;
	int texX;
	double step, wallX;
	char *addr;

	textureSet(vars, &addr, &width, &height);
	drawPixelsSet(vars, &wallX, &texX, width);

	step = (drawStart - screenHeight / 2 + vars->lineHeight / 2) * (1.0 * height / vars->lineHeight);

	while (drawStart <= drawEnd)
	{
		step += (1.0 * height / vars->lineHeight);
		my_mlx_pixel_put(&img, vsop, drawStart, ((int *)addr)[height * ((int)step & (height - 1)) + texX]); /* wall one unit print */
		drawStart++;
	}
}

void drawEnviroment(t_data img, t_vars *vars, int vsop, int drawStart, int drawEnd)
{
	int pixel;
	
	pixel = 0;
	while (pixel < screenHeight)
	{
		if (pixel < drawStart)
			my_mlx_pixel_put(&img, vsop, pixel, create_trgb(0, 0, 200, 200));
		if (pixel < screenHeight  && pixel >= drawEnd)
			my_mlx_pixel_put(&img, vsop, pixel, create_trgb(0, 10, 100, 0));
		pixel++;
	}
}