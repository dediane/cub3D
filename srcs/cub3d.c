/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:04:42 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/02 19:51:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	show_image(t_env *env)
{
	mlx_put_image_to_window(env->params.mlx, \
	env->params.mlx_win, env->img.img, 0, 0);

	// mlx_put_image_to_window(env->params.mlx, \
	// env->params.mlx_win, env->minimap.img, 0, 0);
	return (1);
}

t_img make_image(void *mlx, int width, int height)
{
	t_img img;
	
	img.width = width;
	img.height = height;
	img.img = mlx_new_image(mlx, width, height);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return(img);
}

int     render_next_frame(t_env *env)
{
	//raycasting(env);
    mlx_put_image_to_window(env->params.mlx, env->params.mlx_win, env->img.img, 0, 0);
	//mlx_put_image_to_window(env->params.mlx, env->params.mlx_win, env->minimap.img, 0, 0);
    mlx_do_sync(env->params.mlx);

	return 0;
}



int main(int ac, char **av)
{
	t_env env;

	init_env(&env);
	if (!parsing(ac, av, &env))
	{
		ft_free(&env);
		return (1);
	}
	
	env.params.mlx = mlx_init();
	env.params.res_x = 1280;
	env.params.res_y = 960;
	env.ppi = env.params.res_x / env.width;
	env.params.mlx_win = mlx_new_window(env.params.mlx, env.params.res_x, env.params.res_y, "Cub3D");
	env.img = make_image(env.params.mlx, env.params.res_x, env.params.res_y);
	//init de la map en 2d
	//ft_init_minimap(&env);
	print_all_datas(&env);

	ft_init_ray(&env);
	raycasting(&env);
	//mlx_loop_hook(env.params.mlx, render_next_frame, &env);
	mlx_loop_hook(env.params.mlx, show_image , &env);
	mlx_hook(env.params.mlx_win, 33, 1L << 17, quit_program, &env);
	mlx_hook(env.params.mlx_win, 2, 1L << 0, keypress, &env);
	mlx_loop(env.params.mlx);


	ft_free(&env);
	return (0);
}
