/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:35:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/30 16:05:00 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_init_minimap(t_env *env)
{
	int ratio;
	ratio = env->ppi/5;
	env->minimap = make_image(env->params.mlx, env->width * ratio, env->height * ratio); \
	env->minimap.ratio = ratio;
	env->minimap.width = env->width * env->minimap.ratio;
	env->minimap.height = env->width * env->minimap.ratio;
	draw_minimap(env);
}

void	ft_draw_square_minimap(t_env *env, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->minimap.ratio)
	{
		j = 0;
		while (j < env->minimap.ratio)
		{
			my_mlx_pixel_put(&env->minimap, i + x, j + y, color);
			j++;
		}
		i++;
	}
}

/*void	ft_draw_square_background(t_env *env, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < env->ppi)
	{
		j = -1;
		while(++j < env->ppi)
			my_mlx_pixel_put(&env->img, i + x, j + y, color);
	}
}*/

/*int draw_background(t_env *env)
{
	int y;
	int x;

	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
			ft_draw_square_background(env, x * env->ppi, y * env->ppi, create_trgb(1,255,255,255));
	}
	
	
	return (0);
}*/

int	draw_minimap(t_env *env)
{
	int	y;
	int	x;

	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			if (env->map[y][x] == '1')
				ft_draw_square_minimap(env, x * env->minimap.ratio, \
				y * env->minimap.ratio, create_trgb(1, 64, 194, 212));
			else if (env->map[y][x] == '0')
				ft_draw_square_minimap(env, x * env->minimap.ratio, \
				y * env->minimap.ratio, create_trgb(1, 212, 234, 237));
			else if (env->map[y][x] == 'N' || env->map[y][x] == 'S' \
			|| env->map[y][x] == 'E' || env->map[y][x] == 'W')
				ft_draw_square_minimap(env, x * env->minimap.ratio, \
				y * env->minimap.ratio, create_trgb(1, 161, 108, 213));
			else
				ft_draw_square_minimap(env, x * env->minimap.ratio, y * env->minimap.ratio, \
				create_trgb(1, 255, 255, 255));
		}
	}
	return (0);
}