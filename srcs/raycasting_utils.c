/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:03:27 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/09 11:51:27 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_init_ray(t_env *env)
{
	load_all_textures(env);
	env->ray.pos.x = env->spawn_pos[1];
	env->ray.pos.y = env->spawn_pos[0];
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

int	get_texture_color(t_env *env, t_img img)
{
	int		index;
	int		ptr;
	double	wall;

	if (env->ray.side == 0)
		wall = env->ray.pos.y + env->ray.distance.playerwall * \
		env->ray.camera.raydiry;
	else
		wall = env->ray.pos.x + env->ray.distance.playerwall * \
		env->ray.camera.raydirx;
	wall -= floor(wall);
	env->texx = wall * (double)img.width;
	if (env->ray.side == 0 && env->ray.camera.raydirx < 0)
		env->texx = img.width - env->texx - 1;
	if (env->ray.side == 1 && env->ray.camera.raydiry > 0)
		env->texx = img.width - env->texx - 1;
	index = (env->texy * (img.line_length)) + (env->texx * \
	img.bits_per_pixel / 8);
	ptr = *(int *)&img.addr[max(0, min(index, img.width * img.height * 8))];
	return (ptr);
}

void	draw_texture(t_env *env, int y, t_img current_texture)
{
	int	d;

	d = y * current_texture.height - env->params.res_y * \
	(current_texture.width / 2) + env->ray.lineheight * \
	(current_texture.width / 2);
	env->texy = (((d * current_texture.width) / \
	env->ray.lineheight) / current_texture.height);
	return ;
}

t_img	get_texture(t_env *env)
{
	if (env->ray.side == 1 && env->ray.camera.raydiry < 0)
		return (env->texture.no_texture);
	if (env->ray.side == 1 && env->ray.camera.raydiry > 0)
		return (env->texture.so_texture);
	if (env->ray.side == 0 && env->ray.camera.raydirx < 0)
		return (env->texture.ea_texture);
	if (env->ray.side == 0 && env->ray.camera.raydirx > 0)
		return (env->texture.we_texture);
	return (env->texture.no_texture);
}
