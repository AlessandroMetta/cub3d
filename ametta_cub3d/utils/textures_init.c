#include "../cub3d.h"

static void	init_txt(t_img *txt, void *win_ptr, char *path)
{
	txt->img = mlx_xpm_file_to_image(win_ptr, path, &txt->w, &txt->h);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bpp, &txt->line_length,
			&txt->endian);
}

void	texture_init(t_win win, t_red *config, t_tex *textures)
{
	textures->no = (t_img *)malloc(sizeof(t_img));
	textures->so = (t_img *)malloc(sizeof(t_img));
	textures->ea = (t_img *)malloc(sizeof(t_img));
	textures->we = (t_img *)malloc(sizeof(t_img));
	textures->sp = (t_img *)malloc(sizeof(t_img));
	init_txt(textures->no, win.ptr, config->no_t);
	init_txt(textures->so, win.ptr, config->so_t);
	init_txt(textures->we, win.ptr, config->we_t);
	init_txt(textures->ea, win.ptr, config->ea_t);
	init_txt(textures->sp, win.ptr, config->sp_t);
}
