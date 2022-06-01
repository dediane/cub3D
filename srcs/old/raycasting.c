/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:15:42 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/31 11:10:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void raycasting_1(t_env *env, t_img *img)
{
    (void)img;
    t_rot rot;
    t_ray ray;
    t_ray step;
    t_shape line;
    int x;
    int i;
    double new;
    double c;
    double len;
    (void)len;

    env->ray_params.yaw += 0.01f;
    x = 0;
    i = 0;
    while (x < env->params.res_x)
    {
        c = (x / (float)env->params.res_x) - 0.5;
        new = atan2(c, 0.6);
        
        rot.angle = env->ray_params.yaw + new;
        rot.cos = cos(rot.angle);
        rot.sin = sin(rot.angle);
        
        ray = init_ray(&rot, env->ray_params.px, env->ray_params.py);
        step = init_ray(&rot, 0, 0);
        line.width = 1;
        line.x = x;

        while(i < env->width)
        {
            if (check_colide(ray, env, rot, ray.len_cos > ray.len_sin))
            {
                len = fmin(ray.len_cos, ray.len_sin);
                line.height = env->params.res_y /(len * cos(new));
                line.y = (env->params.res_y - line.height) / 2;
                rect(img, line, 0x00FFFFFF);
                break;
            }
            cast_forward(&ray, step);
            i++;
        }
        x++;
    }
}

void	cast_forward(t_ray *ray, t_ray step)
{
	if (ray->len_cos < ray->len_sin)
	{
			ray->cos_step.x += step.cos_step.x;
			ray->cos_step.y += step.cos_step.y;
			ray->len_cos += step.len_cos;
	}
	else
	{
			ray->sin_step.x += step.sin_step.x;
			ray->sin_step.y += step.sin_step.y;
			ray->len_sin += step.len_sin;
	}
}

int     render_next_frame(t_env *env)
{
	/*t_shape shape;

	shape.width = env->params.res_x;
	shape.height = env->params.res_x;
	shape.x = 0;
	shape.y = 0;
	rect(&(env->img), shape, 0xFFFFFFF);

	raycasting_1(env, &(env->img));*/

    mlx_put_image_to_window(env->params.mlx, env->params.mlx_win, env->img.img, 0, 0);
	//mlx_put_image_to_window(env->params.mlx, env->params.mlx_win, env->minimap.img, 0, 0);
    mlx_do_sync(env->params.mlx);

	return 0;
}