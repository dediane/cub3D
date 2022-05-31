/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:03:27 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/30 18:05:44 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void rect(t_img *img, t_shape shape, int color)
{
    int i;
    int j;

    i = shape.x;
    while (i < shape.x + shape.width && i < img->width)
    {
        j = shape.y;
        while (j < shape.y + shape.height && j < img->height)
        {
            my_mlx_pixel_put(img, i, j, color);
            j++;
        }
        i++;
    }
}

double square(t_vec_double vector)
{
    return sqrt(vector.x * vector.x + vector.y + vector.y);
}

t_ray	init_ray(t_rot * rot, double x, double y)
{
    t_ray ray;
    
    if (rot->sin > 0)
        ray.cos_step.x = floor(x) - x + 1;
    else
        ray.cos_step.x = ceil(x) - x - 1;
    ray.cos_step.y = ray.cos_step.x * (rot->sin / rot->cos);
    ray.len_cos = square(ray.cos_step);
    
    if (rot->sin > 0)
        ray.sin_step.y= floor(y) - y + 1;
    else
        ray.sin_step.y = ceil(y) - y - 1;
    ray.sin_step.x = ray.sin_step.x * (rot->cos / rot->sin);
    ray.len_sin = square(ray.sin_step);
    return (ray);
}

int		check_colide(t_ray ray, t_env *env, t_rot rot, bool up)
{
	int posX;
	int posY;

	if (up)
	{
		posX = floor( env->ray_params.px + ray.sin_step.x);
		posY = floor( env->ray_params.py + ray.sin_step.y);
		if (rot.sin < 0)
			posY--;
	}
	else
	{
		posX = floor(env->ray_params.px + ray.cos_step.x);
		posY = floor(env->ray_params.py + ray.cos_step.y);
		if (rot.cos < 0)
			posX--;
	}

	if (posX < 0 || posX > 19 || posY < 0 || posY > 19)
		return 0;
	return (env->map[posX][posY] > 0);
}