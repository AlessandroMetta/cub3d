#include "../cub3d.h"

int	take_resolution(char *line, t_red *config)
{
	ft_jump_space(&line);
	if (!line)
		return (0);
	if (*line == 'R')
	{
		line++;
		ft_jump_space(&line);
		config->width = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		ft_jump_space(&line);
		config->height = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	return (0);
}

int	set_color(char *line, int *r, int *b, int *g)
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
	return (0);
}

int	take_color(char *line, t_red *config)
{
	int	r;
	int	b;
	int	g;

	if (*line == 'C')
	{
		set_color(line, &r, &g, &b);
		config->c_c = create_trgb(0, r, g, b);
	}
	else if (*line == 'F')
	{
		set_color(line, &r, &g, &b);
		config->f_c = create_trgb(0, r, g, b);
	}
	return (0);
}

char	*take_path(char *line, int jump)
{
	line += jump;
	ft_jump_space(&line);
	return (ft_strdup(line));
}

int	parsing_path(char *line, t_red *config)
{
	if (line[0] == 'E' && line[1] == 'A')
		config->ea_t = take_path(line, 2);
	else if (line[0] == 'N' && line[1] == 'O')
		config->no_t = take_path(line, 2);
	else if (line[0] == 'S' && line[1] == ' ')
		config->sp_t = take_path(line, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		config->so_t = take_path(line, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		config->we_t = take_path(line, 2);
	return (0);
}
