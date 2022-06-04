/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:45:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/04 12:37:07 by ddecourt         ###   ########.fr       */
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

static void	up(t_env *env)
{
	// if ((env->map[(int)(env->ray.pos.x + env->ray.vec.dirx * env->speed)] \
	// [(int)(env->ray.pos.y)]) == '0')
		env->ray.pos.x += env->ray.vec.dirx * env->speed;
	// if ((env->map[(int)(env->ray.pos.x)] \
	// [(int)(env->ray.pos.y + env->ray.vec.diry * env->speed)]) == '0')
		env->ray.pos.y += env->ray.vec.diry * env->speed;
}

static void	down(t_env *env)
{
	// if (env->map[(int)(env->ray.pos.x - env->ray.vec.dirx * env->speed)] \
	// [(int)(env->ray.pos.y)] == '0')
		env->ray.pos.x -= env->ray.vec.dirx * env->speed;
	// if (env->map[(int)(env->ray.pos.x)] \
	// [(int)(env->ray.pos.y - env->ray.vec.diry * env->speed)] == '0')
		env->ray.pos.y -= env->ray.vec.diry * env->speed;
}

static void	left(t_env *env)
{
	// if (env->map[(int)(env->ray.pos.y)] \
	// [(int)(env->ray.pos.x + env->ray.vec.diry * env->speed)] == '0')
		env->ray.pos.x += env->ray.vec.diry * env->speed;
	// if (env->map[(int)(env->ray.pos.y - env->ray.vec.dirx * env->speed)] \
	// [(int)(env->ray.pos.x)] == '0')
		env->ray.pos.y -= env->ray.vec.dirx * env->speed;
}

static void	right(t_env *env)
{
	// if (env->map[(int)(env->ray.pos.y)] \
	// [(int)(env->ray.pos.x - env->ray.vec.diry * env->speed)] == '0')
		env->ray.pos.x -= env->ray.vec.diry * env->speed;
	// if (env->map[(int)(env->ray.pos.y + env->ray.vec.dirx * env->speed)] \
	// [(int)(env->ray.pos.x)] == '0')
		env->ray.pos.y += env->ray.vec.dirx * env->speed;
}

static void	arrow_left(t_env *env)
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

static void	arrow_right(t_env *env)
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
