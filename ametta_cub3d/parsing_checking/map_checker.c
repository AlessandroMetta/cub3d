#include "../cub3d.h"

static int	ret_val(int err_code)
{
	if (err_code == 0)
		printf("%sError: spawn point not found\n", KRED);
	else
		printf("%sError: too many spawn point declear\n", KRED);
	return (0);
}

static int	just_one_player(char **map)
{
	int	x;
	int	y;
	int	pos;

	pos = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NEWS", map[y][x]) && pos)
				return (ret_val(y));
			else if (ft_strchr("NEWS", map[y][x]) && !pos)
				pos++;
			x++;
		}
		y++;
	}
	if (!pos)
		return (ret_val(0));
	return (1);
}

static int	just_right_chars(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("012 NEWS", map[y][x]))
			{
				printf("%sError: character in the map not admitted, ", KRED);
				printf("r:%d, c:%d\n", y, x);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	map_check(char **map)
{
	if (just_one_player(map) && just_right_chars(map) && map_validator(map))
		return (1);
	else
		return (0);
}
