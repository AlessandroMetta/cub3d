#include <mlx.h>
#include <stdio.h>

int     main(void)
{
    void    *mlx;
    void    *win;

    void    *img;
	char	*relative_path = "./test2.xpm";
    int     img_x;
    int     img_y;

    mlx = mlx_init();
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_x, &img_y);
	win = mlx_new_window(mlx, img_x, img_y, "Ciao!");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}
