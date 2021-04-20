#ifndef LIB_H
# define LIB_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>

# define W_CODE 13
# define A_CODE 0
# define S_CODE 1
# define D_CODE 2
# define LA_CODE 123
# define RA_CODE 124
# define ESC_CODE 53

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

static char *map[mapHeight]=
{
  "111111111111111111111111",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000222220000303030001",
  "100000200020000000000001",
  "100000200020000300030001",
  "100000200020000000000001",
  "100000220220000303030001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "144444444000000000000001",
  "140400004000000000000001",
  "140000504000000000000001",
  "140400004000000000000001",
  "140444444000000000000001",
  "140000000000000000000001",
  "144444444000000000000001",
  "111111111111111111111111"
};

typedef struct s_game
{
	void *mlx;
	void *win;
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
}				t_game;

typedef struct s_rc
{
	int		pixelY;
	int		mapX;
	int		mapY;
	double	screenPixel;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		side;
	double	moveSpeed;
	double	rotSpeed;
	int		lineHeight;
	int 	drawStart;
	int 	drawEnd;
}				t_rc;

typedef struct s_data 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

// utils
int		ft_redcross(void);
int		ft_esc(int keycode);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int 	rayCasting(t_game *new);

#endif