#include "../cub3d.h"

static void	spawndir_init(t_player *new, char pos)
{
	new->dir_x = 0;
	new->dir_y = 0;
	new->plane_x = 0;
	new->plane_y = 0;
	if (pos == 'N')
	{
		new->dir_x = 1;
		new->plane_y = 0.66;
	}
	else if (pos == 'S')
	{
		new->dir_x = -1;
		new->plane_y = -0.66;
	}
	else if (pos == 'W')
	{
		new->dir_y = 1;
		new->plane_x = -0.66;
	}
	else if (pos == 'E')
	{
		new->dir_y = -1;
		new->plane_x = 0.66;
	}
}

void	player_pos(char **map, t_player *new)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NEWS", map[y][x]))
			{
				new->pos_x = x + 0.5;
				new->pos_y = y + 0.5;
				spawndir_init(new, map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
