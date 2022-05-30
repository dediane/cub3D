/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:35:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/30 12:47:32 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_init_minimap(t_env *env)
{
	env->minimap = make_image(env->params.mlx, env->params.res_x / 4, \
	env->params.res_y / 4);
	env->minimap.width = env->params.res_x / 4;
	printf("env->minimap.width = %d\n", env->minimap.width);
	printf("env->minimap.height = %d\n", env->minimap.height);
	printf("env->params.res_x = %d\n", env->params.res_x);
	printf("env->params.res_y = %d\n", env->params.res_y);
	printf("Largeur de map -> %d\n", env->width);
	printf("Hauteur de map-> %d\n", env->height);
	env->minimap.height = env->params.res_y / 4;
	env->minimap.ratio = env->minimap.width / env->width;
	printf("ratio-> %d\n", env->minimap.ratio);
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
				create_trgb(1, 0, 0, 0));
		}
	}
	return (0);
}