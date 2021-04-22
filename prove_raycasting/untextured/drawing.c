#include "lib.h"

static int colorSetting(t_vars *vars)
{
	if (vars->side == 1 && vars->rayDirX < 0)
		return(create_trgb(0, 0, 0, 200));
	else if (vars->side == 1 && vars->rayDirX > 0)
		return(create_trgb(0, 200, 0, 0));
	else if (vars->side == 0 && vars->rayDirY < 0)
		return(create_trgb(0, 128, 0, 128));
	else if (vars->side == 0 && vars->rayDirY > 0)
		return(create_trgb(0, 255, 165, 0));
	return(0);
}

void ft_drawline(t_data img, t_vars *vars, int vsop)
{	
	int drawStart = -vars->lineHeight / 2 + screenHeight / 2;
	if(drawStart < 0)
		drawStart = 0;
	int drawEnd = vars->lineHeight / 2 + screenHeight / 2;
	if(drawEnd >= screenHeight)
		drawEnd = screenHeight - 1;
	int osop = 0;
	int color = colorSetting(vars);

	while(osop <= screenHeight)
	{
		if (osop <= drawStart)
			my_mlx_pixel_put(&img, vsop, osop, create_trgb(0, 0, 200, 200));
		else if(drawStart <= drawEnd)
		{
			my_mlx_pixel_put(&img, vsop, drawStart, color); /* wall one unit print */
			drawStart++;
		}
		if (osop < screenHeight  && osop >= drawEnd)
			my_mlx_pixel_put(&img, vsop, osop, create_trgb(0, 10, 100, 0));
		osop++;
	}
}
