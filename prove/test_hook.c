#include <mlx.h>
#include <stdio.h>

#define ESC 53
#define A 0

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;


int             main(void)
{
    t_vars    vars;
	int x, y;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1080, 720, "Hello world!");
	mlx_mouse_get_pos(vars.win, &x, &y);
	printf("posizione mouse: x = %d - y = %d\n", x, y);
    mlx_loop(vars.mlx);
} 
