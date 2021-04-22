#include <mlx.h>
#include <math.h>

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_pixel(int dim, int x, int y, int color, t_data img)
{
	int i = 0, j, temp;
	temp = x;
	while(i < dim)
	{
		j = 0;
		x = temp;
		while(j < dim)
		{
			my_mlx_pixel_put(&img, x++, y, color);
		   	j++;
		}
		y++;
		i++;
	}
}

void put_square(int dim, int color, t_data img)
{
	int x = 0, y = 0, width = 10;
	while (x < dim - width)
		put_pixel(width, x++, y, color, img);
	while (y < dim - width)
		put_pixel(width, x, y++, color, img);
	while (x > 0)
		put_pixel(width, x--, y, color, img);
	while (y > 0)
		put_pixel(width, x, y--, color, img);
}

void put_triangle(int dim, int color, t_data img)
{
	int  y = 0, to_add = 20, x = dim + to_add;
	while (y < dim)
		my_mlx_pixel_put(&img, x, y++, color);
	while (x < dim * 2 + to_add)
		my_mlx_pixel_put(&img, x++, y, color);
	while (y > 0)
		my_mlx_pixel_put(&img, x--, y--, color);
}

void put_octagon(double dim, int color, t_data	img)
{
	double x = 270, y = 0, to_add = x + dim, l = sqrt(pow(dim, 2)/2);
	while (x < to_add)
		my_mlx_pixel_put(&img, x++, y, color);
	while (y < l)
		my_mlx_pixel_put(&img, x++, y++, color);
	while (y < dim + l)
		my_mlx_pixel_put(&img, x, y++, color);
	while (y < dim + l + l)
		my_mlx_pixel_put(&img, x--, y++, color);
	while (x > 270)
		my_mlx_pixel_put(&img, x--, y, color);
	while (y > dim + l)
		my_mlx_pixel_put(&img, x--, y--, color);
	while (y > l)
		my_mlx_pixel_put(&img, x, y--, color);
	while (y > 0)
		my_mlx_pixel_put(&img, x++, y--, color);
}

void put_esagon(int dim, int color, t_data	img)
{
	int x = 400, y = 0, to_add = x + dim;
	while (x < to_add)
		my_mlx_pixel_put(&img, x++, y, color);
	while (y < dim)
	{
		my_mlx_pixel_put(&img, x, y++, color);
		if (y % 2 == 0)
			x++;
	}
	while (y < dim * 2)
	{
		my_mlx_pixel_put(&img, x, y++, color);
		if (y % 2 == 0)
			x--;
	}
	while (x > 400)
		my_mlx_pixel_put(&img, x--, y, color);
	while (y > dim)
	{
		my_mlx_pixel_put(&img, x, y--, color);
		if (y % 2 == 0)
			x--;
	}
	while (y > 0)
	{
		my_mlx_pixel_put(&img, x, y--, color);
		if (y % 2 == 0)
			x++;
	}
}

int put_cyrcle(int dim)
{

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

	put_square(100, color, img);
	put_triangle(100, color, img);
	put_octagon(40, color, img);
	put_esagon(50, color, img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 20);
	mlx_loop(mlx);
}
