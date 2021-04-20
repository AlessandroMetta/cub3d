#include "../cub3d.h"

static void	addLastSprite(t_sprite **lst, double x, double y)
{
	t_sprite	*last;
	t_sprite	*temp;

	temp = (t_sprite *)malloc(sizeof(t_sprite));
	if (!temp)
		printf("%sError: Memory Allocation Failed\n", KRED);
	temp->x = x + 0.5;
	temp->y = y + 0.5;
	temp->next = NULL;
	if (!(*lst))
		*lst = temp;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		if (temp)
			last->next = temp;
	}
	return ;
}

t_sprite	*sprite_init(char **map)
{
	int			x;
	int			y;
	t_sprite	*ret;

	ret = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				addLastSprite(&ret, x, y);
			x++;
		}
		y++;
	}
	return (ret);
}
