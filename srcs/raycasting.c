/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:15:42 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/02 18:06:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_init_ray(t_env *env)
{
	env->pposx = env->spawn_pos[1];
	env->pposy = env->spawn_pos[0];
	env->ray.pos.x = env->spawn_pos[1];//* env->ppi + (env->ppi / 2);
	env->ray.pos.y = env->spawn_pos[0]; //* env->ppi + (env->ppi / 2);
	env->ray.vec.dirx= 0;
	env->ray.vec.diry= -1;
	env->ray.vec.planx= 0.66;
	env->ray.vec.plany= 0;
	env->ray.hit = 0;
}

void    init_ray2(t_env *env, int x)
{
    env->ray.camera.camera = 2 * x / (double)env->params.res_x - 1;
    env->ray.camera.raydirx = env->ray.vec.dirx + env->ray.vec.planx * env->ray.camera.camera;
    env->ray.camera.raydiry = env->ray.vec.diry + env->ray.vec.plany * env->ray.camera.camera;
	env->ray.mapx = (int)env->pposx;
	env->ray.mapy = (int)env->pposy;
	env->ray.pos.x = env->pposx;//* env->ppi + (env->ppi / 2);
	env->ray.pos.y = env->pposy;
    env->ray.distance.deltax = sqrt(1 + (env->ray.camera.raydiry * env->ray.camera.raydiry) / (env->ray.camera.raydirx * env->ray.camera.raydirx));
    env->ray.distance.deltay = sqrt(1 + (env->ray.camera.raydirx * env->ray.camera.raydirx) / (env->ray.camera.raydiry * env->ray.camera.raydiry));
	env->ray.hit = 0;
}

void calculate_step(t_env *env)
{
    if (env->ray.camera.raydirx < 0)
    {
        env->ray.stepx = -1;
        env->ray.distance.sidex = (env->ray.pos.x - env->ray.mapx) * env->ray.distance.deltax;
    }
    else
    {
        env->ray.stepx = 1;
        env->ray.distance.sidex = (env->ray.mapx + 1.0 - env->ray.pos.x ) * env->ray.distance.deltax;
    }
    if (env->ray.camera.raydiry < 0)
    {
        env->ray.stepy = -1;
        env->ray.distance.sidey = (env->ray.pos.y - env->ray.mapy) * env->ray.distance.deltay;
    }
    else
    {
        env->ray.stepy = 1;
        env->ray.distance.sidey = (env->ray.mapy + 1.0 - env->ray.pos.y ) * env->ray.distance.deltay;
    }
}

void    wall(t_env *env)
{
    while(env->ray.hit == 0)
    {
        if (env->ray.distance.sidex < env->ray.distance.sidey)
        {
            env->ray.distance.sidex+= env->ray.distance.deltax;
            env->ray.mapx += env->ray.stepx;
            env->ray.side = 0;
        }
        else
        {
            env->ray.distance.sidey+= env->ray.distance.deltay;
            env->ray.mapy += env->ray.stepy;
            env->ray.side = 1;           
        }
        if (env->map[env->ray.mapy][env->ray.mapx] == '1')
            env->ray.hit = 1;
		else
			env->ray.hit = 0;
    }
}

/*void   stripe(t_env *env)
{
    if (env->ray.side == 0)
		env->ray.distance.playerwall = env->ray.distance.sidex - env->ray.distance.deltax;
	else
		env->ray.distance.playerwall = env->ray.distance.sidey - env->ray.distance.deltay;
	//calculate height of line to draw on screen
	env->ray.lineheight = (int)(env->params.res_y / env->ray.distance.playerwall);
	//calculate lowest and highest pixel to fill in current stripe
	env->ray.drawstart = -env->ray.lineheight / 2 + env->params.res_y / 2;
	if (env->ray.drawstart < 0)
		env->ray.drawstart = 0;
	env->ray.drawend = env->ray.lineheight / 2 + env->params.res_y / 2;
	if(env->ray.drawend >= env->params.res_y)
		env->ray.drawend = env->params.res_y - 1;
}*/

void   stripe(t_env *env)
{
    if (env->ray.side == 0)
	
		env->ray.distance.playerwall = ((double)env->ray.mapx - env->ray.pos.x + (1 - (double)env->ray.stepx) / 2) / env->ray.camera.raydirx;
	else
		env->ray.distance.playerwall = ((double)env->ray.mapy - env->ray.pos.y + (1 - (double)env->ray.stepy) / 2) / env->ray.camera.raydiry;
	//calculate height of line to draw on screen
	env->ray.lineheight = (int)(env->params.res_y / env->ray.distance.playerwall);
	//calculate lowest and highest pixel to fill in current stripe
	env->ray.drawstart = -env->ray.lineheight / 2 + env->params.res_y / 2;
	if (env->ray.drawstart < 0)
		env->ray.drawstart = 0;
	env->ray.drawend = env->ray.lineheight / 2 + env->params.res_y / 2;
	if(env->ray.drawend >= env->params.res_y)
		env->ray.drawend = env->params.res_y - 1;
}

void	draw(t_env *env)
{
	int y;
	
	y = 0;
	while (y < env->ray.drawstart)
	{
		my_mlx_pixel_put(&env->img, env->ray.x, y, 0xF25991);
		y++;
	}
	//y = env->ray.drawstart;
	while (y < env->ray.drawend)
	{
		my_mlx_pixel_put(&env->img, env->ray.x, y, 0x6822EC);
		y++;
	}
	while (y < env->params.res_y)
	{
		my_mlx_pixel_put(&env->img, env->ray.x, y, 0x66D882);
		y++;
	}
}

void raycasting(t_env *env)
{
	env->ray.x = 0;
	while( env->ray.x < env->params.res_x)
	{
		init_ray2(env, env->ray.x);
        calculate_step(env);
        wall(env);
        stripe(env);
		draw(env);
		env->ray.x++;
	}
}
