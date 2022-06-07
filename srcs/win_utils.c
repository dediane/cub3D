/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:45:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/07 20:34:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	quit_program(t_env *env)
{
	mlx_destroy_window(env->params.mlx, env->params.mlx_win);
	mlx_destroy_display(env->params.mlx);
	free(env->params.mlx);
	write(1, "Goodbye!\n", 9);
	exit(1);
}

void	arrow_left(t_env *env)
{
	env->olddirx = env->ray.vec.dirx;
	env->ray.vec.dirx = env->ray.vec.dirx * cos(-env->rotspeed) - \
	env->ray.vec.diry * sin(-env->rotspeed);
	env->ray.vec.diry = env->olddirx * sin(-env->rotspeed) + \
	env->ray.vec.diry * cos(-env->rotspeed);
	env->oldplanex = env->ray.vec.planx;
	env->ray.vec.planx = env->ray.vec.planx * cos(-env->rotspeed) - \
	env->ray.vec.plany * sin(-env->rotspeed);
	env->ray.vec.plany = env->oldplanex * sin(-env->rotspeed) + \
	env->ray.vec.plany * cos(-env->rotspeed);
}

void	arrow_right(t_env *env)
{
	env->olddirx = env->ray.vec.dirx;
	env->ray.vec.dirx = env->ray.vec.dirx * cos(env->rotspeed) - \
	env->ray.vec.diry * sin(env->rotspeed);
	env->ray.vec.diry = env->olddirx * sin(env->rotspeed) + \
	env->ray.vec.diry * cos(env->rotspeed);
	env->oldplanex = env->ray.vec.planx;
	env->ray.vec.planx = env->ray.vec.planx * cos(env->rotspeed) - \
	env->ray.vec.plany * sin(env->rotspeed);
	env->ray.vec.plany = env->oldplanex * sin(env->rotspeed) + \
	env->ray.vec.plany * cos(env->rotspeed);
}

int	keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	else if (key == LEFT)
		left(env);
	else if (key == RIGHT)
		right(env);
	else if (key == UP)
		up(env);
	else if (key == DOWN)
		down(env);
	else if (key == ARROW_LEFT)
		arrow_left(env);
	else if (key == ARROW_RIGHT)
		arrow_right(env);
	else
		return (0);
	mlx_destroy_image(env->params.mlx, env->img.img);
	env->img = make_image(env->params.mlx, env->params.res_x, \
	env->params.res_y);
	raycasting(env);
	return (0);
}

/*int keyrelease(int key, t_env *env)
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
}*/
