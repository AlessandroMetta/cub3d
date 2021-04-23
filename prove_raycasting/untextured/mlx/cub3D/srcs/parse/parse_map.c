/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:25:55 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:38:35 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	valid_char(char c)
{
	if (
		c != '0' && \
		c != '1' && \
		c != '2' && \
		c != 'N' && \
		c != 'S' && \
		c != 'W' && \
		c != 'E' && \
		c != ' ')
	{
		printf("Error\nInvalid Configuration");
		exit(-1);
	}
	return (1);
}

void	check_adj(t_parse *config, int i, int j)
{
	if (i == 0 || j == 0 || j == (int)ft_strlen(config->map[i]) - 1 \
		 || i == matrix_len(config->map) - 1)
		ft_perror("Error\nMap is Invalid");
	if (
		config->map[i][j - 1] == ' ' || \
		config->map[i][j + 1] == ' ' || \
		config->map[i - 1][j] == ' ' || \
		config->map[i + 1][j] == ' ')
		ft_perror("Error\nMap is Invalid");
	if ((config->map[i][j] == 'N' || config->map[i][j] == 'S' || \
			config->map[i][j] == 'W' || config->map[i][j] == 'E'))
	{
		config->spawn[0] = i;
		config->spawn[1] = j;
		config->spawn[2] = config->map[i][j];
		config->spawn[3]++;
	}
}

void	check_spawn(int *ptr)
{
	if (ptr[0] == -1)
	{
		printf("Error\nNo Spawn Point Set");
		exit(-1);
	}
	if (ptr[3] != 0)
	{
		printf("Error\n%d Spawn Points Set", ptr[3] + 1);
		exit(-1);
	}
}

void	check_map(t_parse *config)
{
	int		i;
	int		j;

	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			valid_char(config->map[i][j]);
			if (config->map[i][j] != '1' && config->map[i][j] != ' ')
				check_adj(config, i, j);
			if (config->map[i][j] == '2')
				config->sp_num++;
			j++;
		}
		i++;
	}
	check_spawn(config->spawn);
}

void	parse_map(int fd, t_parse *config)
{
	int		stop;
	char	*line;
	char	*buff;

	stop = 1;
	buff = NULL;
	while (stop > 0)
	{
		stop = get_next_line(fd, &line);
		if (!line && buff)
			ft_perror("Error\nInvalid Map");
		if (is_map(line))
		{
			if (!buff)
				buff = ft_strdup(line);
			else
				buff = ft_append(buff, line);
		}
		free(line);
		line = NULL;
	}
	config->map = ft_split(buff, '\n');
	free(buff);
	check_map(config);
}
