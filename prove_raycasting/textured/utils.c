#include "lib.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->ll + x * (data->bbp / 8));
    *(unsigned int*)dst = color;
}

int	ft_exit(int keycode, t_vars *vars)
{
	/*dont forget to free all mallocs*/
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == c)
	{
		return ((char *)s + i);
	}
	return (NULL);
}
