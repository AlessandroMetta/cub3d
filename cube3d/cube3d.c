#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#define ESC 53

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

int             close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
	    mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
}

/*int             redcross(int keycode, t_vars *vars)
{
	if (vars->win && vars->mlx)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (-1);
}*/

int             pressed(int botton_pressed, t_vars *vars)
{
	printf("botton press = %d\n", botton_pressed);
}

int     main(void)
{
	t_vars    vars;
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1080, 720, "ametta's Cube3d");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
//	mlx_hook(vars.win, 17, 1L<<17, redcross, &vars);
    mlx_loop(vars.mlx);
}       
