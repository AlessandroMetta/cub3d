/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:35:37 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:31:03 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	parse_res(char **args, t_parse *config)
{
	if (matrix_len(args) != 3)
		ft_perror("Error\nInvalid Resolution");
	check_res(args);
	if (config->x_res > 0 || config->y_res > 0)
		ft_perror("Error\nTwo or More Resolutions Specified");
	config->x_res = ft_atoi(args[1]);
	if (config->x_res <= 0)
		ft_perror("Error\nInvalid Resolution");
	config->y_res = ft_atoi(args[2]);
	if (config->y_res <= 0)
		ft_perror("Error\nInvalid Resolution");
}

void	parse_path(char **args, t_parse *config)
{
	int		tmp_fd;

	if (matrix_len(args) != 2)
		ft_perror("Error\nSpecify Only 1 Path");
	tmp_fd = open(args[1], O_RDONLY);
	if ((tmp_fd < 0))
		ft_perror("Error\nTexture File Is Invalid For Some Reason");
	close(tmp_fd);
	if (ft_strcmp(args[0], "NO") && !config->no_path)
		config->no_path = ft_strdup(args[1]);
	else if (ft_strcmp(args[0], "SO") && !config->so_path)
		config->so_path = ft_strdup(args[1]);
	else if (ft_strcmp(args[0], "WE") && !config->we_path)
		config->we_path = ft_strdup(args[1]);
	else if (ft_strcmp(args[0], "EA") && !config->ea_path)
		config->ea_path = ft_strdup(args[1]);
	else if (ft_strcmp(args[0], "S") && !config->sp_path)
		config->sp_path = ft_strdup(args[1]);
	else
		ft_perror("Error\nInvalid Configuration");
}

int	color_check(char **args)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	color_encoder(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		ft_perror("Error\nInvalid Color");
	return (0 | r << 16 | g << 8 | b);
}

void	parse_color(char **args, t_parse *config)
{
	char	**color;

	color = ft_split(args[1], ',');
	if (matrix_len(args) != 2 || matrix_len(color) != 3 || !color_check(color))
		ft_perror("Error\nInvalid Color");
	if (!ft_isdigit(args[1][0]))
		ft_perror("Error\nInvalid Color");
	check_commas(args[1]);
	if (ft_strcmp(args[0], "C") && config->ceiling >= 0)
		ft_perror("Error\nInvalid Configuration");
	if (ft_strcmp(args[0], "F") && config->floor >= 0)
		ft_perror("Error\nInvalid Configuration");
	if (ft_strcmp(args[0], "C") && config->ceiling < 0)
		config->ceiling = color_encoder(ft_atoi(color[0]), \
		 ft_atoi(color[1]), ft_atoi(color[2]));
	if (ft_strcmp(args[0], "F") && config->floor < 0)
		config->floor = color_encoder(ft_atoi(color[0]), \
		 ft_atoi(color[1]), ft_atoi(color[2]));
	free_matrix(color);
}
