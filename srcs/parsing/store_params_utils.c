/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:50:33 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/12 12:42:48 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	len_num(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	return (i);
}

void	secure_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	pass_space(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' '))
		(*i)++;
}

void    finish_line(char *line, int *i)
{
	while(line[*i])
		(*i)++;
}

//load all textures images
int	load_all_textures(t_env *env)
{
	load_texture(env, &(env->texture.no_texture), env->texture.no_path);
	load_texture(env, &(env->texture.so_texture), env->texture.so_path);
	load_texture(env, &(env->texture.we_texture), env->texture.we_path);
	load_texture(env, &(env->texture.ea_texture), env->texture.ea_path);
	return (0);
}
