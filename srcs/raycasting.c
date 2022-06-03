/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:15:42 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/03 12:24:53 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	calculate_step(t_env *env)
{
	if (env->ray.camera.raydirx < 0)
	{
		env->ray.stepx = -1;
		env->ray.distance.sidex = (env->ray.pos.x - env->ray.mapx) * \
		env->ray.distance.deltax;
	}
	else
	{
		env->ray.stepx = 1;
		env->ray.distance.sidex = (env->ray.mapx + 1.0 - env->ray.pos.x) * \
		env->ray.distance.deltax;
	}
	if (env->ray.camera.raydiry < 0)
	{
		env->ray.stepy = -1;
		env->ray.distance.sidey = (env->ray.pos.y - env->ray.mapy) * \
		env->ray.distance.deltay;
	}
	else
	{
		env->ray.stepy = 1;
		env->ray.distance.sidey = (env->ray.mapy + 1.0 - env->ray.pos.y) * \
		env->ray.distance.deltay;
	}
}

void	wall(t_env *env)
{
	while (env->ray.hit == 0)
	{
		if (env->ray.distance.sidex < env->ray.distance.sidey)
		{
			env->ray.distance.sidex += env->ray.distance.deltax;
			env->ray.mapx += env->ray.stepx;
			env->ray.side = 0;
		}
		else
		{
			env->ray.distance.sidey += env->ray.distance.deltay;
			env->ray.mapy += env->ray.stepy;
			env->ray.side = 1;
		}
		if (env->map[env->ray.mapy][env->ray.mapx] == '1')
			env->ray.hit = 1;			
		else
			env->ray.hit = 0;
	}
}

void	stripe(t_env *env)
{
	if (env->ray.side == 0)
		env->ray.distance.playerwall = ((double)env->ray.mapx - \
		env->ray.pos.x + (1 - (double)env->ray.stepx) / 2) / \
		env->ray.camera.raydirx;
	else
		env->ray.distance.playerwall = ((double)env->ray.mapy - \
		env->ray.pos.y + (1 - (double)env->ray.stepy) / 2) / \
		env->ray.camera.raydiry;
	env->ray.lineheight = (int)(env->params.res_y / \
	env->ray.distance.playerwall);
	env->ray.drawstart = -env->ray.lineheight / 2 + env->params.res_y / 2;
	if (env->ray.drawstart < 0)
		env->ray.drawstart = 0;
	env->ray.drawend = env->ray.lineheight / 2 + env->params.res_y / 2;
	if (env->ray.drawend >= env->params.res_y)
		env->ray.drawend = env->params.res_y - 1;
}

/*static t_img find_texture(t_env *env)
{
	int y = env->ray.camera.raydiry;
	int x = env->ray.camera.raydirx;

	if(x > 1 && y >= 1)
		return (env->texture.no_texture);
	if(x < 1 && y < 0)
		return (env->texture.so_texture);
	if(x < 0 && y > 1)
		return (env->texture.ea_texture);
	if(x > 1 && y < 0)
		return (env->texture.we_texture);
	return (env->texture.no_texture);
}*/

void	draw(t_env *env)
{
	int	y;
	int	color;
	//int	d;

	y = 0;
	while (y < env->ray.drawstart)
	{
		my_mlx_pixel_put(&env->img, env->ray.x, y, env->texture.ccl);
		y++;
	}
	while (y < env->ray.drawend)
	{
		/*t_img current_texture;
		
		current_texture = find_texture(env); //get right texture - not functionnal yet;			
		
		//draw la texture
		d = y * 256 - env->params.res_y * 128 + env->ray.lineheight * 128;
		env->texy = (((d * current_texture.width) /
		env->ray.lineheight) / 256);
		color = get_texture_color(env, current_texture);
		my_mlx_pixel_put(&env->img, env->ray.x, y, color);
		y++;*/
		color = 0x6822EC;
		if (env->ray.side == 0)
			color /= 2;
		my_mlx_pixel_put(&env->img, env->ray.x, y, color);
		y++;
	}
	while (y < env->params.res_y)
	{
		my_mlx_pixel_put(&env->img, env->ray.x, y, env->texture.fcl);
		y++;
	}
}

void	raycasting(t_env *env)
{
	env->ray.x = 0;
	while (env->ray.x < env->params.res_x)
	{
		init_ray2(env, env->ray.x);
		calculate_step(env);
		wall(env);
		stripe(env);
		draw(env);
		env->ray.x++;
	}
}
