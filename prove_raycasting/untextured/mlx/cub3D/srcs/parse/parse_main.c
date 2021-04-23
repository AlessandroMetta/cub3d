/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:36:01 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:37:28 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	t_parse_init(t_parse *config)
{
	config->x_res = -1;
	config->y_res = -1;
	config->no_path = NULL;
	config->so_path = NULL;
	config->we_path = NULL;
	config->ea_path = NULL;
	config->sp_path = NULL;
	config->floor = -1;
	config->ceiling = -1;
	config->map = NULL;
	config->spawn[0] = -1;
	config->spawn[3] = -1;
	config->sp_num = 0;
}

int	conf_check(t_parse *config)
{
	if (config->x_res == -1 || \
		config->y_res == -1 || \
		config->no_path == NULL || \
		config->so_path == NULL || \
		config->we_path == NULL || \
		config->ea_path == NULL || \
		config->sp_path == NULL || \
		config->floor == -1 || \
		config->ceiling == -1)
		return (1);
	return (0);
}

int	router(char **args)
{
	if (ft_strcmp(args[0], "R"))
		return (1);
	else if (ft_strcmp(args[0], "NO") || ft_strcmp(args[0], "SO") \
			 || ft_strcmp(args[0], "WE") || ft_strcmp(args[0], "EA") \
			 || ft_strcmp(args[0], "S"))
		return (2);
	else if (ft_strcmp(args[0], "F") || ft_strcmp(args[0], "C"))
		return (3);
	else
		return (0);
}

void	parse_config(int fd, t_parse *config)
{
	char	**args;
	int		stop;
	char	*buffer;

	stop = 1;
	while (conf_check(config) && stop)
	{
		stop = get_next_line(fd, &buffer);
		args = ft_split(buffer, ' ');
		free(buffer);
		if (matrix_len(args) > 1)
		{
			if (router(args) == 1)
				parse_res(args, config);
			else if (router(args) == 2)
				parse_path(args, config);
			else if (router(args) == 3)
				parse_color(args, config);
			else
				ft_perror("Error\nInvalid Configuration");
		}
		free_matrix(args);
	}
	if (conf_check(config))
		ft_perror("Error\nInvalid Configuration");
}

void	parse_main(int fd, t_parse *config)
{
	t_parse_init(config);
	parse_config(fd, config);
	parse_map(fd, config);
}
