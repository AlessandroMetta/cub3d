#include "cub3d.h"

// for debugging
void	print_mat(char **mat)
{
	size_t i;

	i = 0;
	while (mat[i])
	{
		printf("|%s|\n", mat[i]);
		i++;
	}
}

size_t	mat_len(char **mat)
{
	size_t i;

	i = 0;
	if (mat)
	{
		while (mat[i])
			i++;
	}
	return (i);
}

void	copy_mat(char **dest, char **src)
{
	size_t i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

void	add_string_to_mat(char ***mat, char *str)
{
	char	**temp_mat;
	size_t	len_mat;

	len_mat = mat_len(*mat);
	temp_mat = (char **)ft_calloc(sizeof(char*), len_mat + 2);
	copy_mat(temp_mat, *mat);
	temp_mat[len_mat] = ft_strdup(str);
	if (*mat)
		free(*mat);
	*mat = temp_mat;
}
