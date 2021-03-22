#include <mlx.h>
int     render_next_frame(void *YourStruct);

typedef struct	s_data
{
    void		*mlx;
	void    	*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
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
	while(y < 200)
	{
		x = 0;
		while (x < 200)
		{
			my_mlx_pixel_put(img, x, y, img->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 20, 20);
}

int     main(void)
{
	t_data	img;
	int x = 0;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(img.mlx, 500, 500);
	img.color = create_trgb(0, x, x, x);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	x++;
	mlx_loop_hook(img.mlx, put_square, &img);
    mlx_loop(img.mlx);
}
