/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:35:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/25 19:13:54 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_init_minimap(t_env *env)
{
	env->minimap = make_image(env->params.mlx, env->params.res_x/4, env->params.res_y/4);
	env->minimap.width = env->params.res_x/4;
	printf("env->minimap.width = %d\n", env->minimap.width);
	printf("env->minimap.height = %d\n", env->minimap.height);
	printf("env->params.res_x = %d\n", env->params.res_x);
	printf("env->params.res_y = %d\n", env->params.res_y);
	env->minimap.height = env->params.res_y/4;
	ft_minimap(env);
}

void	ft_draw_square_minimap(t_env *env, int x, int y, int color)
{
	int res;
	int i = 0;
	int j = 0;

	res = env->minimap.width/env->width;
	while (i < res)
	{
		j = 0;
		while(j < res)
		{
			my_mlx_pixel_put(&env->minimap, i + x, i + y, color);
			j++;
		}
		i++;
	}
	
}

void	ft_minimap(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < env->minimap.height)
	{
		x = 0;
		while(x < env->minimap.width)
		{
			ft_draw_square_minimap(env, x, y, create_trgb(1, 100, 180, 60));
			x++;
		}
		y++;
	}
}