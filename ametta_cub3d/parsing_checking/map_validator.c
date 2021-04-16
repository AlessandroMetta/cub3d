#include "../cub3d.h"

static int	ret_val(int err_code)
{
	if (err_code == 0)
		printf("%sError: map not allowed\n", KRED);
	else
		printf("%sError: map open in line: %d\n", KRED, err_code);
	return (0);
}

static int	check_around(int i, char *prec, char *curr, char *next)
{
	int	prec_len;
	int	next_len;

	prec_len = ft_strlen(prec) - 1;
	next_len = ft_strlen(next) - 1;
	if (i == 0 || i > prec_len || i > next_len)
		return (0);
	if (prec[i] == ' ' || next[i] == ' ' || curr[i - 1] == ' '
		|| curr[i + 1] == ' ' || curr[i + 1] == '\0')
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
		return (ret_val(0));
	if (row_validator("", map[r], map[r + 1]))
	{
		while (++r < (int)mat_len(map) - 1)
		{
			if (!row_validator(map[r - 1], map[r], map[r + 1]))
				return (ret_val(r + 1));
		}
		if (row_validator("", map[r], map[r - 1]))
			return (1);
	}
	return (ret_val(r + 1));
}
