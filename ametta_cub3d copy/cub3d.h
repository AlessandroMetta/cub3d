#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
#include "libft/libft.h"

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
int				get_next_line(const int fd, char **line);

//			file parsing
int				take_resolution(char *line, t_red *map);
int				take_color(char *line, t_red *map);
int				parsing_path(char *line, t_red *map);
int				map_parsing(char *line, t_red map);
void			add_string_to_mat(char ***mat, char *str);		// map parsing

//			structure checker
int				map_check(char **map);
int				map_validator(char **map);
int				check_info(t_red *info);

#endif