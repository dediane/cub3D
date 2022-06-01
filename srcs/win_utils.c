/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:45:12 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/01 21:24:14 by ddecourt         ###   ########.fr       */
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

static void	right(t_env *env)
{

	double rotspeed = 0.2;
	double oldplanex;
	double olddirix  = env->ray.vec.dirx;
	env->ray.vec.dirx = env->ray.vec.dirx * cos(-rotspeed) - env->ray.vec.diry *
	sin(-rotspeed);
	env->ray.vec.diry = olddirix * sin(-rotspeed) + env->ray.vec.diry *
	cos(-rotspeed);
	oldplanex = env->ray.vec.planx;
	env->ray.vec.planx = env->ray.vec.planx * cos(-rotspeed) - env->ray.vec.plany *
	sin(-rotspeed);
	env->ray.vec.plany = oldplanex * sin(-rotspeed) + env->ray.vec.plany *
	cos(-rotspeed);
}

static void	left(t_env *env)
{

	double rotspeed = 0.2;
	double oldplanex;
	double olddirix  = env->ray.vec.dirx;
	env->ray.vec.dirx = env->ray.vec.dirx * cos(rotspeed) - env->ray.vec.diry *
	sin(rotspeed);
	env->ray.vec.diry = olddirix * sin(rotspeed) + env->ray.vec.diry *
	cos(rotspeed);
	oldplanex = env->ray.vec.planx;
	env->ray.vec.planx = env->ray.vec.planx * cos(rotspeed) - env->ray.vec.plany *
	sin(rotspeed);
	env->ray.vec.plany = oldplanex * sin(rotspeed) + env->ray.vec.plany *
	cos(rotspeed);
}

int keypress(int key, t_env *env)
{
	if (key == ESC)
		quit_program(env);
	else if (key == LEFT){
		printf("LEFT OK\n");
		left(env);
	}
	else if (key == RIGHT) {
		right(env);
		printf("RIGHT OK\n");
	}
	else if (key == UP)
		printf("UP OK\n");
	else if (key == DOWN)
		printf("DOWN OK\n");
	else if (key == ARROW_LEFT)
		printf("ARROW_LEFT OK\n");
	else if (key == ARROW_RIGHT)
		printf("ARROW_RIGHT OK\n");
	else
		return (0);
	mlx_destroy_image(env->params.mlx, env->img.img);
	env->img = make_image(env->params.mlx, env->params.res_x, env->params.res_y);
	raycasting(env);
	return(0);
}

int keyrelease(int key, t_env *env)
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

int print_all_datas(t_env *env)
{
    printf("env->nb_lfile = %d\n", env->nb_lfile);
    printf("env->height = %d\n", env->height);
    printf("env->width = %d\n", env->width);
    printf("env->ppi = %d\n", env->ppi);
    printf("env->count = %d\n", env->count);
    printf("env->spawn_pos[0] = %f\n", env->spawn_pos[0]);
    printf("env->spawn_pos[1] = %f\n", env->spawn_pos[1]);
    printf("env->ppos = %d\n", env->ppos);
    printf("env->params.res_x = %d\n", env->params.res_x);
    printf("env->params.res_y = %d\n", env->params.res_y);
    printf("env->ray.pos.x = %f\n", env->ray.pos.x);
	printf("env->ray.pos.y = %f\n", env->ray.pos.y);
	printf("env->ray.vec.drix= %f\n", env->ray.vec.dirx);
	printf("env->ray.vec.driy= %f\n", env->ray.vec.diry);
	printf("env->ray.vec.planx= %f\n", env->ray.vec.planx);
	printf("env->ray.vec.plany= %f\n", env->ray.vec.plany);
	
	
    return (1);
}