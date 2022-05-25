/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:35:37 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/25 20:59:07 by ddecourt         ###   ########.fr       */
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
	printf("Largeur de map -> %d\n", env->width);
	printf("Hauteur de map-> %d\n", env->height);
	env->minimap.height = env->params.res_y/4;
	
	env->minimap.ratio = env->minimap.width/env->width;
	printf("ratio-> %d\n", env->minimap.ratio);
	ft_minimap(env);
}

void	ft_draw_square_minimap(t_env *env, int x, int y, int color)
{
	int i = 0;
	int j = 0;
	
	while (i < env->minimap.ratio)
	{
		j = 0;
		while(j < env->minimap.ratio)
		{
			my_mlx_pixel_put(&env->minimap, i + x  , j + y, color);
			j++;
		}
		i++;
	}
}

void	ft_minimap(t_env *env)
{
	//draw_minimap(env);
	draw_wall(env);
	
	/*int x;
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
	}*/
}

// int	draw_one_square(t_env *env, int x, int y, int color)
// {
// 	int	tmp;
// 	int	tmp_y;

// 	tmp = 0;
// 	tmp_y = 0;
// 	while (tmp_y < env->minimap.ratio)
// 	{
// 		tmp = 0;
// 		while (tmp < env->minimap.ratio)
// 		{
// 			my_mlx_pixel_put(&(env->minimap), x + tmp, y + tmp_y, color);
// 			tmp++;
// 		}
// 		tmp_y++;
// 	}
// 	return (0);
// }

// int	draw_minimap(t_env *env)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	while (y < env->minimap.height)
// 	{
// 		x = 0;
// 		while(x < env->minimap.width)
// 		{
// 			ft_draw_square_minimap(env, x, y, create_trgb(1, 100, 180, 60));
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }


int	draw_wall(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			// printf("map[y][x] = %c\n", env->map[y][x]);
			// printf("valeur de x = %i\n", x); 
			// printf("valeur de y = %i\n", y);
			if (env->map[y][x] == '1')
				ft_draw_square_minimap(env, x * env->minimap.ratio, y * env->minimap.ratio, create_trgb(1, 255, 0, 0));
			else if (env->map[y][x] == '0')
			 	ft_draw_square_minimap(env, x * env->minimap.ratio, y * env->minimap.ratio, create_trgb(1, 0, 125, 0));
			else
				ft_draw_square_minimap(env, x * env->minimap.ratio, y * env->minimap.ratio, create_trgb(1, 0, 0, 255));
			x++;
		}
		y++;
	}
	return (0);
}


/*int	draw_wall(t_env *env, int countX , int countY)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (env->map[++y][0])
	{
		countX = 0;
		while (env->map[y][++x])
		{
			if (env->map[y][x] == '1')
				ft_draw_square_minimap(env, (countX * env->minimap.ratio), \
				(countY * env->minimap.ratio), create_trgb(1, 170, 50, 60));
			countX++;
		}
		x = -1;
		countY++;
	}
	return (0);
}*/