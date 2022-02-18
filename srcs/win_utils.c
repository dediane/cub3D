#include "../inc/cub3D.h"

int	quit_program(t_env *env)
{
	mlx_destroy_window(env->params.mlx, env->params.mlx_win);
	mlx_destroy_display(env->params.mlx);
	free(env->params.mlx);
	write(1, "goodbye", 7);
	exit(1);
}

int keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	return(0);
}