#ifndef LIB_H
# define LIB_H

#include "map.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <mlx.h>

void	ft_display(void *mlx_ptr);
void	cub3d(void);

typedef struct  s_spt {
    double      posX;
    double      posY;
    struct s_spt *next;
}               t_spt;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bbp;
    int         ll;
    int         end;
    int         wdh;
    int         hgh;
}               t_data;

typedef struct s_keys{
  int  keyUp;
  int  keyDown;
  int  keyLeftView;
  int  keyRightView;
  int  keyLeft;
  int  keyRight;
}             t_keys;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color);

typedef struct  s_vars {
    void        *mlx;
    void        *win;
    double      posX;
    double      posY;  //x and y start position
    double      dirX;
    double      dirY; //initial direction vector
    double      planeX;
    double      planeY; //the 2d raycaster version of camera plane
    double      cameraX; //x-coordinate in camera space
    double      rayDirX;
    double      rayDirY;
    
    //which box of the map we're in
    int         mapX;
    int         mapY;

    //length of ray from current position to next x or y-side
    double      sideDistX;
    double      sideDistY;

    //length of ray from one x or y-side to next x or y-side
    double      deltaDistX;
    double      deltaDistY;
    double      perpWallDist;

    //what direction to step in x or y-direction (either +1 or -1)
    int         stepX;
    int         stepY;

    int         side; //was a NS or a EW wall hit?
    //calculate step and initial sideDist
    int         lineHeight;

    double      oldDirX;
    double      oldPlaneX;
    //keys
    int  keyUp;
    int  keyDown;
    int  keyLeftView;
    int  keyRightView;
    int  keyLeft;
    int  keyRight;
    
    t_data *texN;
    t_data *texS;
    t_data *texE;
    t_data *texW;

}               t_vars;

int		key_hook(int keycode, t_vars *vars);
int		ft_release(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_exit(int keycode, t_vars *vars);
int		ft_release(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void		ft_keys(t_vars *vars);
int		render_next_frame(t_vars *vars);
char	*ft_strchr(const char *s, int c);
int   create_trgb(int t, int r, int g, int b);
void drawTexture(t_data img, t_vars *vars, int vsop, int drawStart, int drawEnd);
void drawEnviroment(t_data img, t_vars *vars, int vsop, int drawStart, int drawEnd);

#endif