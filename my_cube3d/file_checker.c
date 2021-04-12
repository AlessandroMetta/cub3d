#include "cub3d.h"

int	texture_validator(char *file)
{
	if (ft_strrstr(file, "xpm"))
		if (open((const char *)file, O_RDONLY) >= 0)
		{
			close(*file);
			return (1);
		}
	printf("Error: texture %s invalid\n", file);
	return (0);
}

int	texture_check(t_red *info)
{
	if (texture_validator(info->no_t))
		if (texture_validator(info->so_t))
			if (texture_validator(info->ea_t))
				if (texture_validator(info->we_t))
					if (texture_validator(info->sp_t))
						return (1);
	return (0);
}

int	check_info(t_red *info)
{
	if (map_moment(info) && map_check(info->map) && texture_check(info))
		return ();
	else
		return (0);
}