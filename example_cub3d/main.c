#include "lib.h"

int main()
{
  void      *mlx_ptr;
  void      *mlx_win;

  t_vars    vars;

  //screen(screenWidth, screenHeight, 0, "Raycaster");
  mlx_ptr = mlx_init();
  mlx_win = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub3D"); //open window
  // vars.towD_win = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub2D");
  vars.mlx = mlx_ptr; //saving connection ptr to keycode struct
  vars.win = mlx_win; //saving window ptr to keycode struct
  vars.posX = 22; /*player intial positon x */
  vars.posY = 19; /*player intial postion y */
  vars.dirX = -1;
  vars.dirY = 0;
  vars.time = 0 ;
  vars.oldTime =0;
  vars.planeX = 0;
  vars.planeY = 0.66;

  
	//mlx_key_hook(mlx_win, key_hook, &vars); //key read start

	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars); //esc key press exit and free all /*play key press*/
  mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
	mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars); //x button exit and free all

  mlx_loop_hook(mlx_ptr, render_next_frame, &vars); //next frame render //remenber to reverse key and frame
	mlx_loop(mlx_ptr); //in loop key read, push pixel
}