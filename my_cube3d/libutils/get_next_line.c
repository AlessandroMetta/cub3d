/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:53:01 by ppunzo            #+#    #+#             */
/*   Updated: 2021/01/29 13:53:23 by ppunzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static int		lettura(char **n_l, char **save, int fd)
{
	int		red;
	char	*buffer;
	char	*temp;

	red = BUFFER_SIZE;
	while (!(*n_l = ft_strchr(save[fd], '\n')) && (red == BUFFER_SIZE))
	{
		if (!(buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char))))
		{
			free(save[fd]);
			return (-1);
		}
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
		{
			free(save[fd]);
			free(buffer);
			return (-1);
		}
		temp = ft_strjoin(save[fd], buffer);
		free(save[fd]);
		save[fd] = temp;
		free(buffer);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *save[MAX_OPEN];
	char		*n_l;
	char		*temp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || fd > MAX_OPEN)
		return (-1);
	if (!save[fd])
		if (!(save[fd] = (char *)ft_calloc(sizeof(char), 1)))
			return (-1);
	n_l = 0;
	if (lettura(&n_l, save, fd) != 0)
		return (-1);
	if (n_l)
		*n_l = 0;
	*line = ft_strdup(save[fd]);
	if (n_l)
	{
		temp = ft_strdup(n_l + 1);
		free(save[fd]);
		save[fd] = temp;
		return (1);
	}
	free(save[fd]);
	save[fd] = 0;
	return (0);
}
