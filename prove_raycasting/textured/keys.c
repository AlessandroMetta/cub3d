#include "lib.h"

int ft_release(int keycode, t_vars *vars)
{
  keycode == 13 ? vars->keyUp = 0 : 1;
  keycode == 1 ? vars->keyDown = 0 : 1;
  keycode == 123 ? vars->keyLeftView = 0 : 1;
  keycode == 124 ? vars->keyRightView = 0 : 1;
  keycode == 0 ? vars->keyRight = 0 : 1;
  keycode == 2 ? vars->keyLeft = 0 : 1;
  return 0;
}

int	key_hook(int keycode, t_vars *vars)
{
	keycode == 13 ? vars->keyUp = 1 : 0;
	keycode == 1 ? vars->keyDown = 1 : 0;
	keycode == 123 ? vars->keyLeftView = 1 : 0;
	keycode == 124 ? vars->keyRightView = 1 : 0;
	keycode == 0 ? vars->keyRight = 1 : 0;
	keycode == 2 ? vars->keyLeft = 1 : 0;
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return keycode;
}

static void		movement(t_vars *vars)
{
	if(vars->keyUp == 1)	// W
	{
		if(ft_strchr("02NWES", map[(int)(vars->posX + vars->dirX * MOVSPEED)][(int)(vars->posY)]))
			vars->posX = vars->posX + vars->dirX * MOVSPEED;
		if(ft_strchr("02NWES", map[(int)(vars->posX)][(int)(vars->posY + vars->dirY * MOVSPEED)]))
			vars->posY = vars->posY + vars->dirY * MOVSPEED;
	}
	if(vars->keyDown == 1)	// S
	{
		if(ft_strchr("02NWES", map[(int)(vars->posX - vars->dirX * MOVSPEED)][(int)(vars->posY)]))
			vars->posX -= vars->dirX * MOVSPEED;
		if(ft_strchr("02NWES", map[(int)(vars->posX)][(int)(vars->posY - vars->dirY * MOVSPEED)]))
			vars->posY -= vars->dirY * MOVSPEED;
	}
	if(vars->keyLeft == 1)	// A
	{
		if(ft_strchr("02NWES", map[(int)(vars->posX + vars->planeX * MOVSPEED)][(int)(vars->posY)]))
			vars->posX = vars->posX + vars->planeX * MOVSPEED;
		if(ft_strchr("02NWES", map[(int)(vars->posX)][(int)(vars->posY + vars->planeY * MOVSPEED)]))
			vars->posY = vars->posY + vars->planeY * MOVSPEED;
	}
	if(vars->keyRight == 1)	// D
	{
		if(ft_strchr("02NWES", map[(int)(vars->posX - vars->planeX * MOVSPEED)][(int)(vars->posY)]))
			vars->posX -= vars->planeX * MOVSPEED;
		if(ft_strchr("02NWES", map[(int)(vars->posX)][(int)(vars->posY - vars->planeY * MOVSPEED)]))
			vars->posY -= vars->planeY * MOVSPEED;
	}
}

static  void		rotation(t_vars *vars)
{
	if (vars->keyLeftView == 1)	// left arrow
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(ROTSPEED) - vars->dirY * sin(ROTSPEED);
		vars->dirY = vars->oldDirX * sin(ROTSPEED) + vars->dirY * cos(ROTSPEED);
		vars->oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(ROTSPEED) - vars->planeY * sin(ROTSPEED);
		vars->planeY = vars->oldPlaneX * sin(ROTSPEED) + vars->planeY * cos(ROTSPEED);
	}
	if (vars->keyRightView == 1) 	// right arrow
	{
		vars->oldDirX = vars->dirX;
		vars->dirX = vars->dirX * cos(-ROTSPEED) - vars->dirY * sin(-ROTSPEED);
		vars->dirY = vars->oldDirX * sin(-ROTSPEED) + vars->dirY * cos(-ROTSPEED);
		vars->oldPlaneX = vars->planeX;
		vars->planeX = vars->planeX * cos(-ROTSPEED) - vars->planeY * sin(-ROTSPEED);
		vars->planeY = vars->oldPlaneX * sin(-ROTSPEED) + vars->planeY * cos(-ROTSPEED);/*D move right*/
	}
}

void		ft_keys(t_vars *vars)
{
	movement(vars);
	rotation(vars);
}
