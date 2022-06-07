/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:23:34 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/07 19:27:12 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	up(t_env *env)
{
	if ((env->map[(int)env->ray.pos.y][(int)(env->ray.pos.x + \
	env->ray.vec.dirx * env->speed)]) != '1')
		env->ray.pos.x += env->ray.vec.dirx * env->speed;
	if ((env->map[(int)(env->ray.pos.y + env->ray.vec.diry * \
	env->speed)][(int)env->ray.pos.x]) != '1')
		env->ray.pos.y += env->ray.vec.diry * env->speed;
	return ;
}

void	down(t_env *env)
{
	if (env->map[(int)(env->ray.pos.y)][(int)(env->ray.pos.x - \
	env->ray.vec.dirx * env->speed)] != '1')
		env->ray.pos.x -= env->ray.vec.dirx * env->speed;
	if (env->map[(int)(env->ray.pos.y - env->ray.vec.diry * \
	env->speed)][(int)(env->ray.pos.x)] != '1')
		env->ray.pos.y -= env->ray.vec.diry * env->speed;
	return ;
}

void	left(t_env *env)
{
	if (env->map[(int)(env->ray.pos.y)][(int)(env->ray.pos.x + \
	env->ray.vec.diry * env->speed)] != '1')
		env->ray.pos.x += env->ray.vec.diry * env->speed;
	if (env->map[(int)(env->ray.pos.y - env->ray.vec.dirx * \
	env->speed)][(int)(env->ray.pos.x)] != '1')
		env->ray.pos.y -= env->ray.vec.dirx * env->speed;
	return ;
}

void	right(t_env *env)
{
	if (env->map[(int)(env->ray.pos.y)][(int)(env->ray.pos.x - \
	env->ray.vec.diry * env->speed)] != '1')
		env->ray.pos.x -= env->ray.vec.diry * env->speed;
	if (env->map[(int)(env->ray.pos.y + env->ray.vec.dirx * \
	env->speed)][(int)(env->ray.pos.x)] != '1')
		env->ray.pos.y += env->ray.vec.dirx * env->speed;
	return ;
}
