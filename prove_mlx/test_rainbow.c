#include <mlx.h>
#include <stdlib.h>

#define w 1080
#define h 720

static int blu = 0, red = 255, green = 0;

typedef struct	s_data
{
    void		*mlx;
	void    	*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int put_square(t_data *img)
{
	int x = 0, y = 0;
	while(y < h)
	{
		x = 0;
		while (x < w)
		{
			my_mlx_pixel_put(img, x, y, create_trgb(0, red, green, blu));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	
	if (blu == 0)
		while (red > 0)
		{
			red--;
			green++;
			return (0);
		}
	while (green > 0)
	{
		green--;
		blu++;
		return (0);
	}
	while (blu > 0)
	{
		blu--;
		red++;
		return (0);
	}
	return (0);
}

int destroy()
{
	exit(0);
	return (0);
}

int close(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int     main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, w, h, "Hello world!");
	img.img = mlx_new_image(img.mlx, w, h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	mlx_hook(img.win, 17, 1L<<5, destroy, &img);
	mlx_hook(img.win, 2, 1L<<0, close, &img);
	mlx_loop_hook(img.mlx, put_square, &img);
    mlx_loop(img.mlx);
}
