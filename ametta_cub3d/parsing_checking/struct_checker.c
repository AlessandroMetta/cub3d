#include "../cub3d.h"

static int	texture_validator(char *file)
{
	if (ft_strrstr(file, "xpm"))
	{
		if (open((const char *)file, O_RDONLY) >= 0)
		{
			close(*file);
			return (1);
		}
	}
	printf("Error: texture %s invalid\n", file);
	return (0);
}

static int	texture_check(t_red *config)
{
	if (texture_validator(config->no_t))
		if (texture_validator(config->so_t))
			if (texture_validator(config->ea_t))
				if (texture_validator(config->we_t))
					if (texture_validator(config->sp_t))
						return (1);
	return (0);
}

int	map_moment(t_red *config)
{
	if (config->width && config->height && config->no_t && config->so_t
		&& config->ea_t && config->we_t && config->sp_t && config->f_c
		&& config->c_c)
		return (1);
	return (0);
}

int	check_info(t_red *config)
{
	if (map_moment(config) && map_check(config->map) && texture_check(config))
		return (0);
	else
		return (-1);
}
