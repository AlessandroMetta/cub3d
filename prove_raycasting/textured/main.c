#include "lib.h"

void	ft_lstadd_back(t_spt **lst, t_spt *new)
{
	t_spt *last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	if (new)
	{
		last->next = new;
		new->next = NULL;
	}
}
int	ft_lstsize(t_spt *lst)
{
	int counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

void spawnPointInit(t_vars *vars)
{
	int x = 0;
	while (map[x])
	{
		int y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'N')
			{
				vars->posX = x + 0.5;
				vars->posY = y + 0.5;
				vars->dirX = -1;
				vars->dirY = 0;
				vars->planeX = 0;
				vars->planeY = 0.66;
				return ;
			}
			y++;
		}
		x++;
	}
	return ;
}

void spritePosInit(t_spt *spt)
{
	t_spt temp;
	int x = 0;
	while (map[x])
	{
		int y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '2')
			{
				temp.posX = x + 0.5;
				temp.posY = y + 0.5;
				temp.next = NULL;
				ft_lstadd_back(&spt, &temp);
			}
			y++;
		}
		x++;
	}
	printf("sprite number: %d\n", ft_lstsize(spt));
	return ;
}

int main()
{
	void      *mlx_ptr;
	void      *mlx_win;	

	t_vars    vars;
	spawnPointInit(&vars);

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub3D"); //open window
	vars.mlx = mlx_ptr;
	vars.win = mlx_win;

	vars.texN = (t_data *)malloc(sizeof(t_data));
	vars.texN->img = mlx_xpm_file_to_image(vars.mlx, "texture/mossy.xpm", &vars.texN->wdh, &vars.texN->hgh);
	vars.texN->addr = mlx_get_data_addr(vars.texN->img, &vars.texN->bbp, &vars.texN->ll, &vars.texN->end);
	
	vars.texS = (t_data *)malloc(sizeof(t_data));
	vars.texS->img = mlx_xpm_file_to_image(vars.mlx, "texture/redbrick.xpm", &vars.texS->wdh, &vars.texS->hgh);
	vars.texS->addr = mlx_get_data_addr(vars.texS->img, &vars.texS->bbp, &vars.texS->ll, &vars.texS->end);

	vars.texE = (t_data *)malloc(sizeof(t_data));
	vars.texE->img = mlx_xpm_file_to_image(vars.mlx, "texture/stone.xpm", &vars.texE->wdh, &vars.texE->hgh);
	vars.texE->addr = mlx_get_data_addr(vars.texE->img, &vars.texN->bbp, &vars.texE->ll, &vars.texE->end);

	vars.texW = (t_data *)malloc(sizeof(t_data));
	vars.texW->img = mlx_xpm_file_to_image(vars.mlx, "texture/wood.xpm", &vars.texW->wdh, &vars.texW->hgh);
	vars.texW->addr = mlx_get_data_addr(vars.texW->img, &vars.texW->bbp, &vars.texW->ll, &vars.texW->end);

	vars.keyDown = 0;
	vars.keyUp = 0;
	vars.keyRight = 0;
	vars.keyLeft = 0;
	vars.keyLeftView = 0;
	vars.keyRightView = 0;

	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars); //esc key press exit and free all /*play key press*/
	mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
	mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars); //x button exit and free all

	mlx_loop_hook(mlx_ptr, render_next_frame, &vars); //next frame render //remenber to reverse key and frame
	mlx_loop(mlx_ptr); //in loop key read, push pixel
}