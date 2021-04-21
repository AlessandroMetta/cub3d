#include "lib.h"

void spawnPoint(t_game *new)
{
	int y, x;

	new->dirX = 0;
	new->dirY = 0;
	new->planeX = 0;
	new->planeY = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N')
			{
				new->posX = x + 0.5;
				new->posY = y + 0.5;
				new->dirX = -1;
				new->planeY = 0.66;
				return ;
			}
			else if (map[y][x] == 'S')
			{
				new->posX = x + 0.5;
				new->posY = y + 0.5;
				new->dirX = -1;
				new->planeY = -0.66;
				return ;
			}
			else if (map[y][x] == 'W')
			{
				new->posX = x + 0.5;
				new->posY = y + 0.5;
				new->dirY = 1;
				new->planeX = -0.66;
				return ;
			}
			else if (map[y][x] == 'E')
			{
				new->posX = x + 0.5;
				new->posY = y + 0.5;
				new->dirY = -1;
				new->planeX = 0.66;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int main(void)
{
	t_game new;

	spawnPoint(&new);
	printf("%f %f", new.posX, new.posY);
	void *mlx_ptr = mlx_init();
	new.mlx = mlx_ptr;
	new.win = mlx_new_window(new.mlx, screenWidth,
			screenHeight, "ametta Cub3D");
	mlx_hook(new.win, 3, 1L<<1, ft_redcross, &new);
	mlx_hook(new.win, 17, 1L<<5, ft_esc, &new);
	mlx_loop_hook(mlx_ptr, rayCasting, &new);
	mlx_loop(new.mlx);
}
