#include "cub3d.h"

int	just_one_player(char **map)
{
	int x;
	int y;
	int pos;

	pos = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NEWS", map[y][x]) && pos)
				return (0);
			else if (ft_strchr("NEWS", map[y][x]) && !pos)
				pos++;
			x++;
		}
		y++;
	}
	if (!pos)
	{
		printf("Error: spawn point not found\n");
		return(0);
	}
	return (1);
}

int	just_right_chars(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("012 NEWS", map[y][x]))
			{
				printf("Error: character in the map not admitted, r:%d, c:%d\n", y, x);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	map_validator(char **map)
{
	int y;

	y = 0;
	if (mat_len(map) < 3)
		return (0);
	 
}

int	map_check(char **map)
{
	if (just_one_player(map) && just_right_chars(map) && map_validator(map))
		return (1);
	else
		return (0);
}