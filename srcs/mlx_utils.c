/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:20:50 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/09 14:21:42 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	destroy_image(t_env *env)
{
	if (env->texture.no_texture.img)
		mlx_destroy_image(env->params.mlx, env->texture.no_texture.img);
	if (env->texture.so_texture.img)
		mlx_destroy_image(env->params.mlx, env->texture.so_texture.img);
	if (env->texture.we_texture.img)
		mlx_destroy_image(env->params.mlx, env->texture.we_texture.img);
	if (env->texture.ea_texture.img)
		mlx_destroy_image(env->params.mlx, env->texture.ea_texture.img);
}
