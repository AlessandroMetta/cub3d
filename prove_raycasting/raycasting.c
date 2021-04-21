#include "lib.h"

int deltaDistCalculator(double n1, double n2)
{
	if (n2)
	{
		if (n1)
			return (fabs(1 / n1));
		else
			return (1);
	}
	else
		return (0);
}

void dda(t_rc *val)
{
	int hit = 0;
	while(hit == 0)
	{
		if (val->sideDistX < val->sideDistY)
		{
			val->sideDistX += val->deltaDistX;
			val->mapX += val->stepX;
			val->side = 0;
		}
		else
		{
			val->sideDistY += val->deltaDistY;
			val->mapY += val->stepY;
			val->side = 1;
		}
		if (map[val->mapX][val->mapY] == '1' || map[val->mapX][val->mapY] != 'N')
			hit = 1;
	}
}

void drawLine(t_data img, t_rc val)
{
	int pixelStart = val.drawStart;
	int pixelEnd = val.drawEnd;
	int pixelIter = 0;
	int color;

	if (val.side == 1)
		color = create_trgb(0, 200, 100, 0);
	else
		color = create_trgb(0, 200, 200, 0);
	while (pixelIter <= screenHeight)
	{
		// sky
		if (pixelIter <= pixelStart)
			my_mlx_pixel_put(&img, val.pixelY, pixelIter, create_trgb(0, 0, 200, 200));
		// wall
		else if (pixelStart <= pixelEnd)
		{
			my_mlx_pixel_put(&img, val.pixelY, pixelIter, color);
			pixelStart++;
		}
		// ground
		if (pixelIter < screenHeight && pixelIter >= val.drawEnd)
			my_mlx_pixel_put(&img, val.pixelY, pixelIter, create_trgb(0, 10, 100, 0));
		pixelIter++;
	}
	
}

int rayCasting(t_game *new)
{
	t_rc val;
	val.pixelY = -1;
	t_data	img;
	
	img.img = mlx_new_image(new->mlx, screenWidth, screenHeight); //start image
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);//pixel address
	while (val.pixelY++ < screenWidth)
	{
		val.screenPixel = 2 * val.pixelY / (double)screenWidth - 1;
		val.rayDirX = new->dirX + new->planeX * val.screenPixel;
		val.rayDirY = new->dirY + new->planeY * val.screenPixel;
		val.mapX = (int)new->posX;
		val.mapY = (int)new->posY;
		val.deltaDistX = deltaDistCalculator(val.rayDirX, val.rayDirY);
		val.deltaDistY = deltaDistCalculator(val.rayDirY, val.rayDirX);
		
		//calculate step and initial sideDist
		if (val.rayDirX < 0)
		{
			val.stepX = -1;
			val.sideDistX = (new->posX - val.mapX) * val.deltaDistX;
		}
		else
		{
			val.stepX = 1;
			val.sideDistX = (val.mapX + 1.0 - new->posX) * val.deltaDistX;
		}
		if (val.rayDirY < 0)
		{
			val.stepY = -1;
			val.sideDistY = (new->posY - val.mapY) * val.deltaDistY;
		}
		else
		{
			val.stepY = 1;
			val.sideDistY = (val.mapY + 1.0 - new->posY) * val.deltaDistY;
		}
		dda(&val);
		// Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (val.side == 0)
			val.perpWallDist = (val.mapX - new->posX + (1 - val.stepX) / 2) / val.rayDirX;
		else
			val.perpWallDist = (val.mapY - new->posY + (1 - val.stepY) / 2) / val.rayDirY;
		val.lineHeight = (int)(screenHeight / val.perpWallDist);
		val.drawStart = -val.lineHeight / 2 + screenHeight / 2;
		if (val.drawStart < 0)
			val.drawStart = 0;
		val.drawEnd = val.lineHeight / 2 + screenHeight / 2;
		if (val.drawEnd >= screenHeight)
			val.drawEnd = screenHeight - 1;
		drawLine(img, val);
	}
	val.moveSpeed = 0.08;
	val.rotSpeed = 0.02;
	mlx_put_image_to_window(new->mlx, new->win, img.img, 0, 0);
    mlx_destroy_image(new->mlx, img.img);
	return(0);
}