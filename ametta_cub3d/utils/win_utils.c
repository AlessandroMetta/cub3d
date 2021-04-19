#include "../cub3d.h"

static void	resize_to_screen_size(t_red *config, t_win window)
{
	int	max_x;
	int	max_y;

	mlx_get_screen_size(window.ptr, &max_x, &max_y);
	if (config->width > max_x)
		config->width = max_x;
	if (config->height > max_y)
		config->height = max_y;
}

void	start_win(t_win *game, t_red *config)
{
	game->ptr = mlx_init();
	resize_to_screen_size(config, *game);
	game->win = mlx_new_window(game->ptr, config->width, config->height,
			"Hello world!");
}
