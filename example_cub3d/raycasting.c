#include "lib.h"

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

int	render_next_frame(t_vars *vars)
{
    int w = screenWidth;
    int h = screenHeight;
    //int w = 0;
    //int h = 0;
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
      vars->deltaDistX = (vars->rayDirY == 0) ? 0 : ((vars->rayDirX == 0) ? 1 : fabs(1 / vars->rayDirX));
      vars->deltaDistY = (vars->rayDirX == 0) ? 0 : ((vars->rayDirY == 0) ? 1 : fabs(1 / vars->rayDirY));

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
        if(map[vars->mapX][vars->mapY] == '1') vars->hit = 1;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if(vars->side == 0)
        {vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;}
      else
        {vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;}

      //Calculate height of line to draw on screen
      vars->lineHeight = (h / vars->perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      vars->drawStart = -vars->lineHeight / 2 + h / 2;
      if(vars->drawStart < 0)
      {
        vars->drawStart = 0;
      }
      vars->drawEnd = vars->lineHeight / 2 + h / 2;
      if(vars->drawEnd >= h)
      {
        vars->drawEnd = h - 1;
      }
      //draw the pixels of the stripe as a vertical line
      ft_drawline(img, vars);
      //verLine(vars->x, vars->drawStart, vars->drawEnd);
      vars->x++;
    }
    //timing for input and FPS counter
    /*vars->oldTime = vars->time;
    vars->time = clock();
    vars->frameTime = (vars->time - vars->oldTime) / 1000.0; //vars.frameTime is the vars.time this frame has taken, in seconds
    //printf("%f\n",1.0 / vars->frameTime); //FPS counter
*/
    //speed modifiers
    vars->moveSpeed = 0.05;//vars->frameTime * 5.0; //the constant value is in squares/second
    vars->rotSpeed = 0.02;//vars->frameTime * 3.0; //the constant value is in radians/second
    
    // draw2D(vars);
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
    mlx_destroy_image(vars->mlx, img.img);
    ft_keys(vars);
    return (0);
}
