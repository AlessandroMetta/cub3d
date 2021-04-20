#include "lib.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	ft_redcross(void)
{
	exit(0);
}

int	ft_esc(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}