/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:55:19 by ametta            #+#    #+#             */
/*   Updated: 2021/04/09 19:05:44 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

typedef struct	s_specs
{
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
}				t_specs;

int ft_jump_space(char **str)
{
	while (*str && ft_strchr(" \t\v\f\r", **str))
		*str += 1;
	return 0;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int take_resolution(char *line, t_specs *map)
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

int set_color(char *line, int *r, int *b, int *g)
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

int take_color(char *line, t_specs *map)
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

int take_path(char *line, t_specs *map)
{
	if (line[0] == 'E' && line[1] == 'A')
	{
		line += 2;
		ft_jump_space(&line);
		map->ea_t = ft_strdup(line);
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		line += 2;
		ft_jump_space(&line);
		map->no_t = ft_strdup(line);
	}
	else if (line[0] == 'S' && line[1] == ' ')
	{
		line += 2;
		ft_jump_space(&line);
		map->sp_t = ft_strdup(line);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		line += 2;
		ft_jump_space(&line);
		map->so_t = ft_strdup(line);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		line += 2;
		ft_jump_space(&line);
		map->we_t = ft_strdup(line);
	}
	return 0;
}

void take_file(t_specs *map)
{
	char	*line = 0;
	int		file = 0;
	
	map->width = 0, map->height = 0;
	map->no_t = 0, map->so_t = 0, map->ea_t = 0, map->we_t = 0;
	map->sp_t = 0;
	map->f_c = 0, map->c_c = 0;

	file = open("map.cub", O_RDONLY);
	while(get_next_line(file, &line))
	{
		take_resolution(line, map);
		take_color(line, map);s
		take_path(line, map);
		free(line);
	}	
}

void	init_struct_specs(t_specs *map)
{
	map->width = 0;
	map->height = 0;
	map->no_t = 0;
	map->so_t = 0;
	map->ea_t = 0;
	map->we_t = 0;
	map->sp_t = 0;
	map->f_c = 0;
	map->c_c = 0;
}

void	debug_struct_specs(t_specs map)
{
	printf("width:			%d\nheight:			%d\n", map.width, map.height);
	printf("path north:		%s\n", map.no_t);
	printf("path south:		%s\n", map.so_t);
	printf("path east:		%s\n", map.ea_t);
	printf("path west:		%s\n", map.we_t);
	printf("path sprite:		%s\n", map.sp_t);
	printf("path floor color: 	%d\n", map.f_c);
	printf("path ceiling color:	%d\n", map.c_c);
}

int						main(void)				// <-- Here start everithing
{
	t_specs	map;
	init_struct_specs(&map);
	take_file(&map);
	debug_struct_specs(map);	
	return 0;
	/*
	t_game	all;
	t_key	keys;
	all.player.posX = 22, all.player.posY = 12;		// posizione di creazione del giocatore all;interno della mappa 
	all.player.dirX = -1, all.player.dirY = 0;		// direzione della visale del giocatore
	all.player.planeX = 0, all.player.planeY = 0.66;	// angolo di visuale

	all.mlx.ptr = mlx_init();
    all.mlx.win = mlx_new_window(all.mlx.ptr, screenWidth, screenHeight, "ametta's Cube3d");  //creazione della finestra

	mlx_hook(all.mlx.win, 2, 1L<<0, key_pressed, &keys);
	mlx_hook(all.mlx.win, 3, 1L<<1, key_release, &keys);

	mlx_hook(all.mlx.win, 17, 1L<<5, red_cross, &all.mlx);
	mlx_loop_hook(all.mlx.ptr, ft_render, &all.mlx);
    mlx_loop(all.mlx.ptr);
	*/
}
