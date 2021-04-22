#include "lib.h"

void spawnPointInit(t_vars *vars)
{
	int x = 0;
	while (map[x])
	{
		int y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'N')
			{
				vars->posX = x + 0.5;
				vars->posY = y + 0.5;
				vars->dirX = -1;
				vars->dirY = 0;
				vars->planeX = 0;
				vars->planeY = 0.66;
				return ;
			}
			y++;
		}
		x++;
	}
	return ;
}

int main()
{
	void      *mlx_ptr;
	void      *mlx_win;	

	t_vars    vars;
	
	spawnPointInit(&vars);

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub3D"); //open window
	
	vars.mlx = mlx_ptr;
	vars.win = mlx_win;
	vars.keyDown = 0;
	vars.keyUp = 0;
	vars.keyRight = 0;
	vars.keyLeft = 0;
	vars.keyLeftView = 0;
	vars.keyRightView = 0;

	vars.tex.no = (t_data *)malloc(sizeof(t_data));
	vars.tex.so = (t_data *)malloc(sizeof(t_data));
	vars.tex.ea = (t_data *)malloc(sizeof(t_data));
	vars.tex.we = (t_data *)malloc(sizeof(t_data));

	vars.dirX = -1;
	vars.dirY = 0;
	vars.planeX = 0;
	vars.planeY = 0.66;

	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars); //esc key press exit and free all /*play key press*/
	mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
	mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars); //x button exit and free all

	mlx_loop_hook(mlx_ptr, render_next_frame, &vars); //next frame render //remenber to reverse key and frame
	mlx_loop(mlx_ptr); //in loop key read, push pixel
}