/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:03:27 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/02 20:15:43 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_init_ray(t_env *env)
{
	env->ray.pos.x = env->spawn_pos[1];
	env->ray.pos.y = env->spawn_pos[0];
	env->ray.vec.dirx = 0;
	env->ray.vec.diry = -1;
	env->ray.vec.planx = 0.66;
	env->ray.vec.plany = 0;
	env->ray.hit = 0;
	env->speed = 0.2;
	env->rotspeed = 0.2;
}

void	init_ray2(t_env *env, int x)
{
	env->ray.camera.camera = 2 * x / (double)env->params.res_x - 1;
	env->ray.camera.raydirx = env->ray.vec.dirx + env->ray.vec.planx * \
	env->ray.camera.camera;
	env->ray.camera.raydiry = env->ray.vec.diry + env->ray.vec.plany * \
	env->ray.camera.camera;
	env->ray.mapx = (int)env->ray.pos.x;
	env->ray.mapy = (int)env->ray.pos.y;
	env->ray.distance.deltax = sqrt(1 + (env->ray.camera.raydiry * \
	env->ray.camera.raydiry) / (env->ray.camera.raydirx * \
	env->ray.camera.raydirx));
	env->ray.distance.deltay = sqrt(1 + (env->ray.camera.raydirx * \
	env->ray.camera.raydirx) / (env->ray.camera.raydiry * \
	env->ray.camera.raydiry));
	env->ray.hit = 0;
}
