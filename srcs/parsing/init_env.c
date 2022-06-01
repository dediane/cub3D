/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:58:02 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/01 11:49:10 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	init_env(t_env *env)
{
	env->map = NULL;
	env->nb_lfile = 0;
	env->height = 0;
	env->width = 0;
	env->ppi = 0;
	env->count = 0;
	env->spawn_pos[0] = 0;
	env->spawn_pos[1] = 0;
	env->ppos = 0;
	init_texture(&env->texture);
}

void	init_texture(t_texture *texture)
{
	texture->no_path = NULL;
	texture->so_path = NULL;
	texture->we_path = NULL;
	texture->ea_path = NULL;
	texture->fd_no = 0;
	texture->fd_so = 0;
	texture->fd_we = 0;
	texture->fd_ea = 0;
	texture->f = false;
	texture->c = false;
	texture->fcl = 0;
	texture->ccl = 0;
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			if (map[i])
			{
				free(map[i]);
				map[i] = NULL;
			}
			i++;
		}
		free(map[i]);
		map[i] = NULL;
		free(map);
		map = NULL;
	}
}

void	ft_free(t_env *env)
{
	if (env->texture.no_path)
		free(env->texture.no_path);
	if (env->texture.so_path)
		free(env->texture.so_path);
	if (env->texture.we_path)
		free(env->texture.we_path);
	if (env->texture.ea_path)
		free(env->texture.ea_path);
	ft_free_map(env->map);
}
