#include "cube3d.h"

int		main(int ac, char **av)				// <-- Everithing start here
{
	t_specs	map;
	if (ac >= 2 && ac <= 3)
	{
		init_struct_specs(&map);
		if (ac > 2 && ft_strrstr(av[2], "--save"))
			map.save = 1;
		if (ft_strrstr(av[1], ".cub"))
			map.path = ft_strdup(av[1]);
		take_file(&map);
		debug_struct_specs(map);
	}
	else
		printf("Error: the number of argument is worng\n");
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

void	take_file(t_specs *map)
{
	char	*line = 0;
	int		fd = 0;

	fd = open(map->path, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		take_resolution(line, map);
		parsing_path(line, map);
		take_color(line, map);
		free(line);
		if (map_moment(map))
			break;
	}
	while(get_next_line(fd, &line))
	{
		if(ft_strlen(line))
			add_string_to_mat(&map->map, line);
		free(line);
	}
	add_string_to_mat(&map->map, line);
	free(line);
}