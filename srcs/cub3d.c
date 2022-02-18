/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:04:42 by ddecourt          #+#    #+#             */
/*   Updated: 2022/01/29 10:44:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	show_image(t_env *env)
{
	mlx_put_image_to_window(env->params.mlx, \
	env->params.mlx_win, env->img.img, 0, 0);
	return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_env env;

	if (ac != 2)
		return (ft_putstr("Usage: [./cub3D.c] [map.cub]"), 2);
	//if (!(ft_check_map(av[1], &env)))
	//	return (ft_putstr("Error\ncheck map invalid."), 2);
	env.params.mlx = mlx_init();
	mlx_get_screen_size(env.params.mlx, &env.params.screen_x, &env.params.screen_y);
	env.params.mlx_win = mlx_new_window(env.params.mlx, env.params.screen_x/1.5, env.params.screen_y/1.5, "Cub3d");
	mlx_loop(env.params.mlx);
	
}
