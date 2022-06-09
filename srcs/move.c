/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:23:34 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/09 12:29:23 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	up(t_env *env)
{
	if ((env->map[(int)env->ray.pos.y][(int)(env->ray.pos.x + \
	env->ray.vec.dirx * env->speed)]) != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->ray.pos.x += env->ray.vec.dirx * env->speed;
		env->change = 1;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	if ((env->map[(int)(env->ray.pos.y + env->ray.vec.diry * \
	env->speed)][(int)env->ray.pos.x]) != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->ray.pos.y += env->ray.vec.diry * env->speed;
		env->change = 1;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	return ;
}

void	down(t_env *env)
{
	if (env->map[(int)(env->ray.pos.y)][(int)(env->ray.pos.x - \
	env->ray.vec.dirx * env->speed)] != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->ray.pos.x -= env->ray.vec.dirx * env->speed;
		env->change = 1;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	if (env->map[(int)(env->ray.pos.y - env->ray.vec.diry * \
	env->speed)][(int)(env->ray.pos.x)] != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->ray.pos.y -= env->ray.vec.diry * env->speed;
		env->change = 1;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	return ;
}

void	left(t_env *env)
{
	if (env->map[(int)(env->ray.pos.y)][(int)(env->ray.pos.x + \
	env->ray.vec.diry * env->speed)] != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->ray.pos.x += env->ray.vec.diry * env->speed;
		env->change = 1;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	if (env->map[(int)(env->ray.pos.y - env->ray.vec.dirx * \
	env->speed)][(int)(env->ray.pos.x)] != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->change = 1;
		env->ray.pos.y -= env->ray.vec.dirx * env->speed;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	return ;
}

void	right(t_env *env)
{
	if (env->map[(int)(env->ray.pos.y)][(int)(env->ray.pos.x - \
	env->ray.vec.diry * env->speed)] != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->ray.pos.x -= env->ray.vec.diry * env->speed;
		env->change = 1;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	if (env->map[(int)(env->ray.pos.y + env->ray.vec.dirx * \
	env->speed)][(int)(env->ray.pos.x)] != '1')
	{
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = '0';
		env->ray.pos.y += env->ray.vec.dirx * env->speed;
		env->change = 1;
		env->map[(int)env->ray.pos.y][(int)env->ray.pos.x] = env->pos;
	}
	return ;
}
