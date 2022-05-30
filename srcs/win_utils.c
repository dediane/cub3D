#include "../inc/cub3D.h"

int	quit_program(t_env *env)
{
	mlx_destroy_window(env->params.mlx, env->params.mlx_win);
	mlx_destroy_display(env->params.mlx);
	free(env->params.mlx);
	write(1, "Goodbye!\n", 9);
	exit(1);
}

int keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	else if (key == LEFT)
		printf("LEFT OK\n");
	else if (key == RIGHT)
		printf("RIGHT OK\n");
	else if (key == UP)
		printf("UP OK\n");
	else if (key == DOWN)
		printf("DOWN OK\n");
	else if (key == ARROW_LEFT)
		printf("ARROW_LEFT OK\n");
	else if (key == ARROW_RIGHT)
		printf("ARROW_RIGHT OK\n");
	return(0);
}