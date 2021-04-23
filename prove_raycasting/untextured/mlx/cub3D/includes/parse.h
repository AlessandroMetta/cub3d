/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:38:16 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:24:48 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# include <stdlib.h>
# include <stdio.h>

typedef struct s_parse
{
	int				x_res;
	int				y_res;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*sp_path;
	int				floor;
	int				ceiling;
	char			**map;
	int				spawn[4];
	int				sp_num;
	int				save;
}				t_parse;

/*
** parse_args.c
*/
void			parse_res(char **args, t_parse *config);
void			parse_path(char **args, t_parse *config);
void			parse_color(char **args, t_parse *config);

/*
** parse_map.c
*/
void			parse_map(int fd, t_parse *config);

/*
** parse_utils.c
*/
int				matrix_len(char **matrix);
void			ft_perror(char *error);
void			free_matrix(char **ptr);
int				is_map(char *line);
char			*ft_append(char *dst, char *src);
void			check_commas(char *color);
void			check_res(char **args);

#endif
