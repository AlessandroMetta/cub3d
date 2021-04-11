#include "cube3d.h"

int		take_resolution(char *line, t_specs *map)
{
	if (line[0] == 'R')
	{
		line++;
		ft_jump_space(&line);
		map->width = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		ft_jump_space(&line);
		map->height = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		ft_jump_space(&line);
	}
	return 0;
}

int		set_color(char *line, int *r, int *b, int *g)
{
	line++;
	ft_jump_space(&line);
		
	*r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line == ',')
		line++;

	*g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line == ',')
		line++;
			
	*b = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line == ',')
		line++;
	return 0;
}

int		take_color(char *line, t_specs *map)
{
	int t = 0, r = 0, b = 0, g = 0;
	if (*line == 'C')
	{
		set_color(line, &r, &g, &b);
		map->c_c = create_trgb(0, r, g, b);
	}
	else if (*line == 'F')
	{
		set_color(line, &r, &g, &b);
		map->f_c = create_trgb(0, r, g, b);
	}
	return 0;
}

char	*take_path(char *line, int jump)
{
	line += jump;
	ft_jump_space(&line);
	return (ft_strdup(line));
}

int		parsing_path(char *line, t_specs *map)
{
	if (line[0] == 'E' && line[1] == 'A')
		map->ea_t = take_path(line, 2);
	else if (line[0] == 'N' && line[1] == 'O')
		map->no_t = take_path(line, 2);
	else if (line[0] == 'S' && line[1] == ' ')
		map->sp_t = take_path(line, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		map->so_t = take_path(line, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		map->we_t = take_path(line, 2);
	return 0;
}

int map_parsing(char *line, t_specs map)
{
	return (0);
}