#ifndef	CUB3D_H
#	define	CUB3D_H

#include	<stdio.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"libutils/libutils.h"

typedef	struct	s_red
{
	int			save;
	int			width;
	int			height;
	char		*no_t;
	char		*ea_t;
	char		*we_t;	
	char		*so_t;
	char		*sp_t;
	int			c_c;
	int			f_c;
	char		**map;
}				t_red;

//			Utils
int				ft_jump_space(char **str);
int				create_trgb(int t, int r, int g, int b);
void			init_struct_specs(t_red *map);
void			debug_struct_specs(t_red map);
int				map_moment(t_red *map);
int				ft_strrstr(char *haystack, char *needle);
int				ret_err(int err_code);
void			print_mat(char **mat);
size_t			mat_len(char **mat);

//			file parsing
int				take_resolution(char *line, t_red *map);
int				take_color(char *line, t_red *map);
int				parsing_path(char *line, t_red *map);
int				map_parsing(char *line, t_red map);
void			add_string_to_mat(char ***mat, char *str);      // map parsing

/*
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>

#define ESC 53				// definizione tasto ESC

#define W 13				// definizione tasto W
#define A 0					// definizione tasto A
#define S 1					// definizione tasto S
#define D 2					// definizione tasto D

#define LA 123				// definizione tasto freccia sinistra
#define RA 124				// definizione tasto freccia destra

#define mapDim 24			// definizione della dimensione della mappa
#define screenWidth 640		// definizione della larghezza dello schermo
#define screenHeight 480	// definizione dell'alltezza dello schermo

int mapGrind[mapDim][mapDim]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct	s_mlx
{
		void    *ptr;
		void    *win;
}				t_mlx;

typedef struct	s_player
{
		double	posX;
		double	posY;
		double	dirX;
		double	dirY;
		double	planeX;
		double	planeY;
}				t_player;

typedef struct	s_data
{
		void	*img;
		char	*addr;
		int     bits_per_pixel;
		int		line_length;
		int		endian;
}				t_data;

typedef struct	s_key
{
		int		keyUp;
		int		keyDown;
		int		keyLeft;
		int		keyRight;
		int		keyRotLeft;
		int		keyRotRight;
}				t_key;

typedef struct	s_game
{
	t_player	player;
	t_mlx		mlx;
}				t_game;


int				key_pressed(int keycode, t_key *arg);
int				key_release(int keycode, t_key *arg);
int				red_cross(int keycode, t_game *arg);

int				ft_render(t_game *arg);
*/
#endif