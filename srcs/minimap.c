/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:34:23 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/09 11:59:20 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_draw_square_minimap(t_env *env, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->minimap.ratio)
	{
		j = -1;
		while (++j < env->minimap.ratio)
			my_mlx_pixel_put(&env->img, i + x, j + y, color);
	}
}

int	minimap(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	env->minimap.ratio = (env->params.res_x / 4) / env->width;
	//printf("env->minimap.ratio = %d\n", env->minimap.ratio);
	ft_draw_square_minimap(env, 0, 0, 0X05FF6F);
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			if (env->map[y][x] == '1')
				ft_draw_square_minimap(env, x * env->minimap.ratio, y * env->minimap.ratio, create_trgb(1, 42, 75, 239));
			else if (env->map[y][x] == '0')
				ft_draw_square_minimap(env, x * env->minimap.ratio, y * env->minimap.ratio, create_trgb(1, 66, 243, 229));
			else
				ft_draw_square_minimap(env, x * env->minimap.ratio, y * env->minimap.ratio, create_trgb(1, 48, 175, 0));
			x++;
		}
		y++;
	}
	return (0);
}
