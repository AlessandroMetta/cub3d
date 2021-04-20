#include "cub3d.h"

void	ft_gameplay(t_red *config)
{
	t_win		game;
	t_player	p1;
	t_tex		textures;
	t_sprite	*sprite_list;

	start_win(&game, config);
	player_pos(config->map, &p1);
	texture_init(game, config, &textures);
	sprite_list = sprite_init(config->map);
	mlx_hook(game.win, 17, 1L <<5, ft_redcross, &game);
	mlx_hook(game.win, 2, 1L <<0, ft_esc, &game);
	mlx_loop(game.ptr);
}

int	fill_info(t_red *config, char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) && !map_moment(config))
	{
		take_resolution(line, config);
		parsing_path(line, config);
		take_color(line, config);
		free(line);
	}
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line))
			add_string_to_mat(&config->map, line);
		free(line);
	}
	add_string_to_mat(&config->map, line);
	free(line);
	if (check_info(config) == -1)
		return (-1);
	ft_gameplay(config);
	return (0);
}

int	main(int ac, char **av)
{
	t_red	config;

	if (ac >= 2 && ac <= 3)
	{
		init_struct_specs(&config);
		if (ac > 2 && ft_strrstr(av[2], "--save"))
			config.save = 1;
		if (ft_strrstr(av[1], ".cub"))
			return (ret_err(fill_info(&config, av[1])));
		else
			return (ret_err(2));
		return (0);
	}
	else
		return (ret_err(1));
}
