#include "cube3d.h"

// funzione che chiude la finestra e termina il programma in caso si prema ESC
int             key_pressed(int keycode, t_key *arg)
{
	keycode == W ? arg->keyUp = 1 : 0;
	keycode == A ? arg->keyRight = 1 : 0;
	keycode == S ? arg->keyDown = 1 : 0;
	keycode == D ? arg->keyLeft = 1 : 0;
	keycode == LA ? arg->keyRotLeft = 1 : 0;
	keycode == RA ? arg->keyRotRight = 1 : 0;
	if (keycode == ESC)
	{
	    exit(0);
	}
	return (0);

}

int				key_release(int keycode, t_key *arg)
{
	keycode == W ? arg->keyUp = 0 : 1;
	keycode == A ? arg->keyRight = 0 : 1;
	keycode == S ? arg->keyDown = 0 : 1;
	keycode == D ? arg->keyLeft = 0 : 1;
	keycode == LA ? arg->keyRotLeft = 0 : 1;
	keycode == RA ? arg->keyRotRight = 0 : 1;
	return 0;
}

// funzione che chiude la finestra e termina il programma in caso si clicchi la croce ross
int             red_cross(int keycode, t_game *arg)
{
	exit(0);
	return (0);
}
