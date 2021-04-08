/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:51:38 by saluru            #+#    #+#             */
/*   Updated: 2021/03/26 11:09:46 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx/mlx.h"
#include <stdio.h>

void	ft_display(void *mlx_ptr);
void	cub3d(void);

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color);

typedef struct  s_vars {
    void        *towD_win; //unusefull

    void        *mlx;
    void        *win;

    int         x;		// stripe of pixel to print

    double      posX;
    double      posY; 	// spawn position
    double      dirX;
    double      dirY;	// spwn direction
    double      planeX;
    double      planeY;	// the 2d raycaster version of camera plane
    double      time;	// unuseful: time of current frame
    double      oldTime;// unuseful: time of previous frame
    double      cameraX;//x-coordinate in camera space
    double      rayDirX;
    double      rayDirY;

    // which box of the map we're in
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

    int         hit; //was there a wall hit?
    int         side; //was a NS or a EW wall hit?
    //calculate step and initial sideDist
    int         lineHeight;

      //calculate lowest and highest pixel to fill in current stripe
    int         drawStart;
    int         drawEnd;
    double      frameTime;
    double      moveSpeed; //the constant value is in squares/second
    double      rotSpeed;
    double      oldDirX;
    double      oldPlaneX;
    //keys
    int  keyUp;
    int  keyDown;
    int  keyLeftView;
    int  keyRightView;
    int  keyLeft;
    int  keyRight;

}               t_vars;

int	key_hook(int keycode, t_vars *vars);
int            ft_release(int keycode, t_vars *vars);

#endif
