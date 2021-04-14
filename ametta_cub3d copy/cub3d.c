#include "cub3d.h"

int	fill_info(t_red *info, char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		take_resolution(line, info);
		parsing_path(line, info);
		take_color(line, info);
		free(line);
		if (map_moment(info))
			break ;
	}
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line))
			add_string_to_mat(&info->map, line);
		free(line);
	}
	add_string_to_mat(&info->map, line);
	free(line);
	if (check_info(info) == -1)
		printf("Error: The map is incorrect");
	else
	{
		printf("The map is correct");
		debug_struct_specs(*info);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_red	info;

	if (ac >= 2 && ac <= 3)
	{
		init_struct_specs(&info);
		if (ac > 2 && ft_strrstr(av[2], "--save"))
			info.save = 1;
		if (ft_strrstr(av[1], ".cub"))
			fill_info(&info, av[1]);
		else
			return (ret_err(2));
		return (0);
	}
	else
		return (ret_err(1));
}
