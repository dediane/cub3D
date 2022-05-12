/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:58:02 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/12 16:12:03 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	init_env(t_env *env)
{
	env->map = NULL;
	env->nb_lfile = 0;
	env->height = 0;
	env->width = 0;
	env->ppi = 0;				// voir avec diane
	env->count = 0;				// voir avec diane (nb pas ?)
	env->spawn_pos[0] = 0;
	env->spawn_pos[1] = 0;
	env->ppos = 0;
	//env->img = NULL;
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
	// j'ai pas init les *img des no, so, we, ea
}

void	ft_free(t_env *env)
{
	int	i;

	i = 0;
	if (env->texture.no_path)
		free(env->texture.no_path);
	if (env->texture.so_path)
		free(env->texture.so_path);
	if (env->texture.we_path)
		free(env->texture.we_path);
	if (env->texture.ea_path)
		free(env->texture.ea_path);
	printf("ici avant free map\n");
	if (env->map)
	{
		printf("-----FREEEE MAAAAP----\n");
		while (env->map[i])
		{
			printf("free map[%d]\n", i);
			if (env->map[i])
				free(env->map[i]);
			i++;
		}
		free(env->map);
	}
	printf("ici apres free map\n");
}
