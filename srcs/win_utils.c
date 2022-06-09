/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:45:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/09 14:19:45 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	quit_program(t_env *env)
{
	destroy_image(env);
	mlx_destroy_image(env->params.mlx, env->img.img);
	mlx_destroy_window(env->params.mlx, env->params.mlx_win);
	mlx_destroy_display(env->params.mlx);
	free(env->params.mlx);
	ft_free(env);
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
	env->change = 1;
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
	env->change = 1;
}

int	keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	else if (key == LEFT)
		env->key.left = 1;
	else if (key == RIGHT)
		env->key.right = 1;
	else if (key == UP)
		env->key.up = 1;
	else if (key == DOWN)
		env->key.down = 1;
	else if (key == ARROW_LEFT)
		env->key.arrow_left = 1;
	else if (key == ARROW_RIGHT)
		env->key.arrow_right = 1;
	return (0);
}

int	keyrelease(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	else if (key == LEFT)
		env->key.left = 0;
	else if (key == RIGHT)
		env->key.right = 0;
	else if (key == UP)
		env->key.up = 0;
	else if (key == DOWN)
		env->key.down = 0;
	else if (key == ARROW_LEFT)
		env->key.arrow_left = 0;
	else if (key == ARROW_RIGHT)
		env->key.arrow_right = 0;
	return (0);
}
