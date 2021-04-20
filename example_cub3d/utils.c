#include "lib.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	ft_exit(int keycode, t_vars *vars)
{
	/*dont forget to free all mallocs*/
	exit(0);
}