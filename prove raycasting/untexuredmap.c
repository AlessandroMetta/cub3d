#include "lib.h"

int main(void)
{
	t_game new;

	new.posX = 22 + 0.5, new.posY = 12 + 0.5;
	new.dirX = -1, new.dirY = 0;
	new.planeX = 0, new.planeY = 0.66;
	void *mlx_ptr = mlx_init();
	new.mlx = mlx_ptr;
	new.win = mlx_new_window(new.mlx, screenWidth,
			screenHeight, "ametta Cub3D");
	mlx_loop_hook(mlx_ptr, rayCasting, &new);
	mlx_loop(new.mlx);
}
