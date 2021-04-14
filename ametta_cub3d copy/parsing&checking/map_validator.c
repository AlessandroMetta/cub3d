#include "../cub3d.h"

static int	check_around(int i, char *prec, char *curr, char *next)
{
	int	prec_len;
	int	next_len;

	prec_len = ft_strlen(prec) - 1;
	next_len = ft_strlen(next) - 1;
	if (i == 0 || i > prec_len || i > next_len)
		return (0);
	if (prec[i] == ' ' || next[i] == ' ' || curr[i - 1] == ' '
		|| curr[i + 1] == ' ')
		return (0);
	return (1);
}

static int	row_validator(char *prec, char *curr, char *next)
{
	int	i;

	i = 0;
	while (curr[i])
	{
		if (ft_strchr("02NEWS", curr[i]))
			if (!check_around(i, prec, curr, next))
				return (0);
		i++;
	}
	return (1);
}

int	map_validator(char **map)
{
	int	r;

	r = 0;
	if (mat_len(map) < 3)
		return (0);
	if (row_validator("", map[r], map[r + 1]))
	{
		while (++r < (int)mat_len(map) - 1)
			if (!row_validator(map[r - 1], map[r], map[r + 1]))
				return (0);
		if (row_validator("", map[r], map[r - 1]))
			return (1);
	}
	return (0);
}
