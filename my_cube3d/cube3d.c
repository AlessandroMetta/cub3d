/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:55:19 by ametta            #+#    #+#             */
/*   Updated: 2021/04/08 18:23:42 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cube3d.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void take_map()
{
	char	*line = 0;
	int		file;

	file = open("map.cub", 00);
	while(get_next_line(file, &line))
	{
		printf("%s\n", line);
		free(line);
	}
}

int						main(void)				// <-- Here start everithing
{
	take_map();
	return 0;
	/*
	t_game	all;
	t_key	keys;
	all.player.posX = 22, all.player.posY = 12;		// posizione di creazione del giocatore all;interno della mappa 
	all.player.dirX = -1, all.player.dirY = 0;		// direzione della visale del giocatore
	all.player.planeX = 0, all.player.planeY = 0.66;	// angolo di visuale

	all.mlx.ptr = mlx_init();
    all.mlx.win = mlx_new_window(all.mlx.ptr, screenWidth, screenHeight, "ametta's Cube3d");  //creazione della finestra

	mlx_hook(all.mlx.win, 2, 1L<<0, key_pressed, &keys);
	mlx_hook(all.mlx.win, 3, 1L<<1, key_release, &keys);

	mlx_hook(all.mlx.win, 17, 1L<<5, red_cross, &all.mlx);
	mlx_loop_hook(all.mlx.ptr, ft_render, &all.mlx);
    mlx_loop(all.mlx.ptr);
	*/
}