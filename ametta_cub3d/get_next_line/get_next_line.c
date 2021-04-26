/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:28:49 by ametta            #+#    #+#             */
/*   Updated: 2021/04/26 14:28:52 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_alloc(char **line, ssize_t more_space)
{
	if (!*line)
	{
		*line = malloc((more_space + 1) * sizeof(char));
		if (!(*line))
			return (-1);
	}
	else
	{
		*line = ft_realloc(*line, ft_strlen(*line) + more_space + 2);
	}
	return (0);
}

int	ft_buffer_handler(int fd, char **line, char buff[MAX_F][BUFFER_SIZE])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[fd][i] == '\n')
		{
			buff[fd][i] = 0;
			(*line)[j] = 0;
			return (1);
		}
		if (buff[fd][i] != 0)
		{
			(*line)[j] = buff[fd][i];
			buff[fd][i] = 0;
			j++;
		}
		i++;
	}
	(*line)[j] = 0;
	return (0);
}

int	ft_read_handler(int fd, char **line,
	char buff[MAX_F][BUFFER_SIZE], ssize_t c_red)
{
	ssize_t	b;
	ssize_t	j;

	b = 0;
	j = ft_strlen(*line);
	while (b < c_red)
	{
		if (buff[fd][b] == '\n')
		{
			buff[fd][b] = 0;
			(*line)[j] = 0;
			return (-1);
		}
		(*line)[j++] = buff[fd][b];
		buff[fd][b++] = 0;
	}
	(*line)[j] = 0;
	return (j);
}

int	get_next_line(int fd, char **line)
{
	static char		buff[MAX_F][BUFFER_SIZE];
	ssize_t			c_red;
	ssize_t			j;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd > MAX_F)
		return (-1);
	*line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*line))
		return (-1);
	if (ft_buffer_handler(fd, line, buff) == 1)
		return (1);
	j = ft_strlen(*line);
	c_red = read(fd, buff[fd], BUFFER_SIZE);
	while (c_red > 0)
	{
		if (ft_is_alloc(line, c_red) < 0)
			return (-1);
		j = ft_read_handler(fd, line, buff, c_red);
		if (j < 0)
			return (1);
	}
	if (c_red < 0)
		return (-1);
	return (0);
}
