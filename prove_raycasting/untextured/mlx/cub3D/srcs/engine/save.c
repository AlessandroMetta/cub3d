/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:09:47 by kpersich          #+#    #+#             */
/*   Updated: 2021/04/08 17:58:21 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

void	set_char(unsigned char *header, int i)
{
	*header = (unsigned char)i;
	*(header + 1) = (unsigned char)(i >> 8);
	*(header + 2) = (unsigned char)(i >> 16);
	*(header + 3) = (unsigned char)(i >> 24);
}

void	write_header(int fd, int width, int height, int bpp)
{
	int				i;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char) 0;
	header[0] = (unsigned char) 'B';
	header[1] = (unsigned char) 'M';
	set_char(&header[2], (width * height) * (bpp / 8) + 54);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	set_char(&header[18], width);
	set_char(&header[22], height);
	header[26] = (unsigned char) 1;
	header[28] = (unsigned char)(32);
	set_char(&header[34], width * height);
	write(fd, header, 54);
}

void	save(t_vars *vars)
{
	int				fd;
	int				i;
	unsigned int	*line;

	if (!vars->parse.save)
		return ;
	i = 0;
	fd = open("deepthought.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	write_header(fd, vars->parse.x_res, vars->parse.y_res,
								vars->img.bpp);
	while (i < vars->parse.y_res)
	{
		line = (unsigned int *)&vars->img.addr[(vars->parse.y_res - i++ - 1) \
			*vars->img.line_length];
		write(fd, line, vars->img.line_length);
	}
	close(fd);
	vars->parse.save = 0;
	exit(0);
}
