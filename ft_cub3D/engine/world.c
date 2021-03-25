/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:48:40 by saluru            #+#    #+#             */
/*   Updated: 2021/03/25 17:55:30 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1920
#define screenHeight 1080
#define wallThick 15
#define gap 3
#define playerSize 5
#define FOV 0.66
#define PI 3.14159
#define MOVSPEED 0.1
#define ROTSPEED 0.05

int worldMap[mapWidth][mapHeight]= {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,0,4,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,4,1,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/*verLine(x, vars.drawStart, vars.drawEnd, color);//print line pixel
redraw(); ft_drawline
cls(); destroy
done(); mlx_loop
readKeys(); mlx_hook
keyDown(SDLK_UP); key_hook
*/
//clock_t clock(void);
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
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

int	ft_exit(int keycode, t_vars *vars)
{
	/*dont forget to free all mallocs*/
	exit(0);
}

int	ft_mouse(int x, int y, t_vars *vars)
{
	/*
	if(x < 1890 && x > 0)
		vars->x = x;
	//printf("\n%d:",y);
	if (y < 1080-40 && y > 0)
		vars->y = y;
	*/
	return (0);
}

void ft_drawline(t_data img, t_vars *vars)
{
    int a = vars->drawStart;
    int b = vars->drawEnd;
    int x = 0;
    int color;

    if(vars->side == 1)
      color = 0X00ABFFAF;
    else
      color = 0x00FFFF00;
    while(x <= screenHeight)
    {
      //sky
      if (x <= a)
        my_mlx_pixel_put(&img, vars->x, x, 0x000000FF);
      //wall
      else if(a <= b)
      {
        my_mlx_pixel_put(&img, vars->x, a, color); /* wall one unit print */
        a++;
      }
      //ground
      //my_mlx_pixel_put(&img, vars->x, a + 1, color);
      if (x < screenHeight  && x >= vars->drawEnd)
        my_mlx_pixel_put(&img, vars->x, x, 0x0000FF00);
      x++;
    }
    //my_mlx_pixel_put(&img, 300, 300, 0x00FF0000);
    //printf("%d: %d : %d\n", a, vars->x, b);
}

void  draw2D(t_vars *vars)
{
    t_data	img;

    img.img = mlx_new_image(vars->mlx, screenWidth, screenHeight); //start image
	  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);//pixel addres
    my_mlx_pixel_put(&img, vars->posX, vars->posY, 0x00FF0000);
    mlx_put_image_to_window(vars->mlx, vars->towD_win, img.img, 0, 0);
    mlx_destroy_image(vars->mlx, img.img);
}

int	render_next_frame(t_vars *vars)
{
    int w = screenWidth;
    int h = screenHeight;
    t_data	img;

    vars->x = 0;
    img.img = mlx_new_image(vars->mlx, screenWidth, screenHeight); //start image
	  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);//pixel address
    while(vars->x < w)
    {
      //calculate ray position and direction
      vars->cameraX = 2 * vars->x / (double)w - 1; //x-coordinate in camera space
      vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
      vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
      //which box of the map we're in
      vars->mapX = vars->posX;
      vars->mapY = vars->posY;

      //length of ray from current position to next x or y-side

       //length of ray from one x or y-side to next x or y-side
      // Alternative code for deltaDist in case division through zero is not supported
      // vars->deltaDistX = (vars->rayDirY == 0) ? 0 : ((vars->rayDirX == 0) ? 1 : fabs(1 / vars->rayDirX));
      if (vars->rayDirY == 0)
        vars->deltaDistX = 0;
      else
      {
        if (vars->rayDirX == 0)
          vars->deltaDistX = 1;
        else
          vars->deltaDistX = fabs(1 / vars->rayDirX);
      }
      // vars->deltaDistY = (vars->rayDirX == 0) ? 0 : ((vars->rayDirY == 0) ? 1 : fabs(1 / vars->rayDirY));
      if (vars->rayDirX == 0)
        vars->deltaDistY = 0;
      else
      {
        if (vars->rayDirY == 0)
          vars->deltaDistY = 1;
        else
          vars->deltaDistY = fabs(1 / vars->rayDirY);
      }
      //what direction to step in x or y-direction (either +1 or -1)
      vars->hit = 0; //was there a wall vars.hit?
      //calculate step and initial sideDist
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
      //perform DDA
      while (vars->hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
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
        //Check if ray has vars.hit a wall
        if(worldMap[vars->mapX][vars->mapY] > 0)
          vars->hit = 1;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if(vars->side == 0)
        vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;
      else
        vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;

      //Calculate height of line to draw on screen
      vars->lineHeight = (h / vars->perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      vars->drawStart = -vars->lineHeight / 2 + h / 2;
      if(vars->drawStart < 0)
        vars->drawStart = 0;
      vars->drawEnd = vars->lineHeight / 2 + h / 2;
      if(vars->drawEnd >= h)
        vars->drawEnd = h - 1;
      //draw the pixels of the stripe as a vertical line
      ft_drawline(img, vars);
      //verLine(vars->x, vars->drawStart, vars->drawEnd);
      vars->x++;
    }
    //speed modifiers
    vars->moveSpeed = 0.08;//vars->frameTime * 5.0; //the constant value is in squares/second
    vars->rotSpeed = 0.02;//vars->frameTime * 3.0; //the constant value is in radians/second
    
//    draw2D(vars);
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
    mlx_destroy_image(vars->mlx, img.img);
    ft_keys(vars);
    return (0);
}

int main()
{
  void      *mlx_ptr;
  void      *mlx_win;

  t_vars    vars;

  //screen(screenWidth, screenHeight, 0, "Raycaster");
  mlx_ptr = mlx_init();
  mlx_win = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub3D"); //open window
//  vars.towD_win = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub2D");
  vars.mlx = mlx_ptr; //saving connection ptr to keycode struct
  vars.win = mlx_win; //saving window ptr to keycode struct
  vars.posX = 22; /*player intial positon x */
  vars.posY = 19; /*player intial postion y */
  vars.dirX = -1;
  vars.dirY = 0;
//  vars.time = 0 ;
//  vars.oldTime = 0;
  vars.planeX = 0;
  vars.planeY = 0.66;

  
	//mlx_key_hook(mlx_win, key_hook, &vars); //key read start

	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars); //esc key press exit and free all /*play key press*/
  mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
	mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars); //x button exit and free all
	mlx_hook(vars.win, 6, 1L<<6, ft_mouse, &vars); //mouse read

  mlx_loop_hook(mlx_ptr, render_next_frame, &vars); //next frame render //remenber to reverse key and frame
	mlx_loop(mlx_ptr); //in loop key read, push pixel
}
