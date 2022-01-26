/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:58:02 by ddecourt          #+#    #+#             */
/*   Updated: 2022/01/25 19:08:11 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	init_env(t_env *env)
{
	env->map = NULL;
	env->height = 0;
	env->width = 0;
	env->ppi = 0;
	env->count = 0;
	env->spawn_pos[0] = 0;
	env->spawn_pos[1] = 0;
	env->ppos = 0;
	env->params = NULL;
	env->img = NULL;
	env->texture = NULL;
}