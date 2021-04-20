#include "lib.h"

int ft_release(int keycode, t_vars *vars)
{
  keycode == 13 ? vars->keyUp = 0 : 1;
  keycode == 1 ? vars->keyDown = 0 : 1;
  keycode == 123 ? vars->keyLeftView = 0 : 1;
  keycode == 124 ? vars->keyRightView = 0 : 1;
  keycode == 0 ? vars->keyRight = 0 : 1;
  keycode == 2 ? vars->keyLeft = 0 : 1;
  //printf("%d:%d\n", vars->keyUp, vars->keyDown);
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
  //printf("%d:%d\n", vars->keyUp, vars->keyDown);
 /*dont forget to free all mallocs*/
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	/*change the return value*/
	return keycode;
}

int		ft_keys(t_vars *vars)
{
	//key strock output function
    
    if(vars->keyUp == 1)//w
    {
      //printf("flag\n");
      if(worldMap[(int)(vars->posX + vars->dirX * vars->moveSpeed)][(int)(vars->posY)] == 0)
        {vars->posX = vars->posX + vars->dirX * vars->moveSpeed;}
        //printf("%d",(int)(vars->posX));
      if(worldMap[(int)(vars->posX)][(int)(vars->posY + vars->dirY * vars->moveSpeed)] == 0)
        {vars->posY = vars->posY + vars->dirY * vars->moveSpeed;}
    }
    if(vars->keyDown == 1)//rightarr View
    {
      if(worldMap[(int)(vars->posX - vars->dirX * vars->moveSpeed)][(int)(vars->posY)] == 0)
        {vars->posX -= vars->dirX * vars->moveSpeed;}
      if(worldMap[(int)(vars->posX)][(int)(vars->posY - vars->dirY * vars->moveSpeed)] == 0)
        {vars->posY -= vars->dirY * vars->moveSpeed;}
    }
    if(vars->keyLeftView == 1)//leftarr view
    {
      //both camera direction and camera plane must be rotated
      vars->oldDirX = vars->dirX;
      vars->dirX = vars->dirX * cos(vars->rotSpeed) - vars->dirY * sin(vars->rotSpeed);
      vars->dirY = vars->oldDirX * sin(vars->rotSpeed) + vars->dirY * cos(vars->rotSpeed);
      vars->oldPlaneX = vars->planeX;
      vars->planeX = vars->planeX * cos(vars->rotSpeed) - vars->planeY * sin(vars->rotSpeed);
      vars->planeY = vars->oldPlaneX * sin(vars->rotSpeed) + vars->planeY * cos(vars->rotSpeed);
    }
    if(vars->keyRightView == 1)//D
    {
      //both camera direction and camera plane must be rotated
      vars->oldDirX = vars->dirX;
      
      vars->dirX = vars->dirX * cos(-vars->rotSpeed) - vars->dirY * sin(-vars->rotSpeed);
      vars->dirY = vars->oldDirX * sin(-vars->rotSpeed) + vars->dirY * cos(-vars->rotSpeed);
      
      vars->oldPlaneX = vars->planeX;
      
      vars->planeX = vars->planeX * cos(-vars->rotSpeed) - vars->planeY * sin(-vars->rotSpeed);
      vars->planeY = vars->oldPlaneX * sin(-vars->rotSpeed) + vars->planeY * cos(-vars->rotSpeed);/*D move right*/
    }
  
    if(vars->keyLeft == 1)
    {
      if(worldMap[(int)(vars->posX + vars->planeX * vars->moveSpeed)][(int)(vars->posY)] == 0)
        {vars->posX = vars->posX + vars->planeX * vars->moveSpeed;}
        //printf("%d",(int)(vars->posX));
      if(worldMap[(int)(vars->posX)][(int)(vars->posY + vars->planeY * vars->moveSpeed)] == 0)
        {vars->posY = vars->posY + vars->planeY * vars->moveSpeed;}
    }
    if(vars->keyRight == 1)
    {
      if(worldMap[(int)(vars->posX - vars->planeX * vars->moveSpeed)][(int)(vars->posY)] == 0)
        {vars->posX -= vars->planeX * vars->moveSpeed;}
      if(worldMap[(int)(vars->posX)][(int)(vars->posY - vars->planeY * vars->moveSpeed)] == 0)
        {vars->posY -= vars->planeY * vars->moveSpeed;}
    }
	return 0 ;
}
