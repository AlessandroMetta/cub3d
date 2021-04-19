#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"

# define W_CODE 13
# define A_CODE 0
# define S_CODE 1
# define D_CODE 2
# define LA_CODE 123
# define RA_CODE 124
# define ESC_CODE 53

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			w;
	int			h;
}				t_img;

typedef struct	s_tex
{
	t_img		*no;
	t_img		*we;
	t_img		*ea;
	t_img		*so;
	t_img		*sp;
}				t_tex;

typedef struct	s_sprite
{
	double		x;
	double		y;
}				t_sprite;

typedef struct s_red
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

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			dir_x;
	int			dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_win
{
	void		*ptr;
	void		*win;
}				t_win;

//			Utils
int				ft_jump_space(char **str);
int				create_trgb(int t, int r, int g, int b);
void			init_struct_specs(t_red *config);
void			debug_struct_specs(t_red config);
int				map_moment(t_red *config);
int				ft_strrstr(char *haystack, char *needle);
int				ret_err(int err_code);
void			print_mat(char **mat);
size_t			mat_len(char **mat);
int				get_next_line(const int fd, char **line);

//			file parsing
int				take_resolution(char *line, t_red *config);
int				take_color(char *line, t_red *config);
int				parsing_path(char *line, t_red *config);
int				map_parsing(char *line, t_red config);
void			add_string_to_mat(char ***mat, char *str);		// map parsing

//			structure checker
int				map_check(char **map);
int				map_validator(char **map);
int				check_info(t_red *config);

void			start_win(t_win *game, t_red *config);
void			player_pos(char **map, t_player *new);
void			texture_init(t_win win, t_red *config, t_tex *textures);

#endif