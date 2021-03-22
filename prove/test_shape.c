#include <mlx.h>

typedef struct	s_data
{
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

int main()
{
	void	*mlx;
	void    *mlx_win;
	t_data	img;
	int		color = 0x00FFFFFF;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 200, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 200);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

	int x = 20, y = 20;
	// quadrato
	while (x < 120)
    	my_mlx_pixel_put(&img, x++, y, color);
	while (y < 120)
    	my_mlx_pixel_put(&img, x, y++, color);
	while (x > 20)
    	my_mlx_pixel_put(&img, x--, y, color);
	while (y > 20)
    	my_mlx_pixel_put(&img, x, y--, color);

	// triangolo
	x = 140, y = 20;
	while (y < 120)
    	my_mlx_pixel_put(&img, x, y++, color);
	while (x < 240)
    	my_mlx_pixel_put(&img, x++, y, color);
	while (y > 20)
    	my_mlx_pixel_put(&img, x--, y--, color);

	// ottagono
	x = 300, y = 20;
	while (x < 344)
    	my_mlx_pixel_put(&img, x++, y, color);
	while (y < 56)
    	my_mlx_pixel_put(&img, x++, y++, color);
	while (y < 100)
    	my_mlx_pixel_put(&img, x, y++, color);
	while (y < 136)
    	my_mlx_pixel_put(&img, x--, y++, color);
	while (x > 300)
    	my_mlx_pixel_put(&img, x--, y, color);
	while (y > 100)
    	my_mlx_pixel_put(&img, x--, y--, color);
	while (y > 56)
    	my_mlx_pixel_put(&img, x, y--, color);
	while (y > 20)
    	my_mlx_pixel_put(&img, x++, y--, color);
	
	// esagono
	x = 450, y = 20;
	while (x < 494)
    	my_mlx_pixel_put(&img, x++, y, color);
	while (x < 530)
    	my_mlx_pixel_put(&img, x++, y++, color);
	while (x > 494)
    	my_mlx_pixel_put(&img, x--, y++, color);
	while (x > 450)
    	my_mlx_pixel_put(&img, x--, y, color);
	while (y > 56)
    	my_mlx_pixel_put(&img, x--, y--, color);
	while (y > 20)
    	my_mlx_pixel_put(&img, x++, y--, color);

	//cerchio
	x = 600, y = 20;

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
