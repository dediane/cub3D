/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:04:42 by ddecourt          #+#    #+#             */
/*   Updated: 2022/02/18 16:37:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	show_image(t_env *env)
{
	mlx_put_image_to_window(env->params.mlx, \
	env->params.mlx_win, env->img.img, 0, 0);
	return (1);
}

void 	randomise_map()
{
	int x,
	int y;
	x = 0;
	while (x < 20)
	{
		y = 0;
		while (y < 20)
		(
			map[x][y] = 0;
			if (rand() % 5 == 4)
				map[x][y] = 1;
			y++;
		)
		x++;
	}
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
	mlx_hook(env.params.mlx_win, 33, 1L << 17, quit_program, &env);
	mlx_hook(env.params.mlx_win, 2, 1L << 0, keypress, &env);
	mlx_loop(env.params.mlx);

}
