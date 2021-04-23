/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:51:47 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:34:36 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	ft_perror(char *error)
{
	ft_putstr_fd(error, 2);
	exit(-1);
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		i++;
	}
	return (i);
}

void	free_matrix(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	is_map(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (0);
	return (1);
}

char	*ft_append(char *dst, char *src)
{
	int	i;

	i = (int)ft_strlen(dst);
	dst = (char *)ft_realloc(dst, ft_strlen(src) + ft_strlen(dst) + 2);
	dst[i] = '\n';
	ft_strcpy(&dst[i + 1], src);
	return (dst);
}
